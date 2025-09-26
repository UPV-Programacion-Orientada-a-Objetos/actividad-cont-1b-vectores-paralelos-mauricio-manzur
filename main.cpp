#include <iostream>
#include <fstream>

// esta variable guardián establece cuantos elementos hay actualmente en los arreglos (sirve para hacer los ciclos for menos pesados)
int cantidadInventario = 0;

// defino el prototipo de las funciones de la aplicación
void inicio();
void consultarProducto(int *codigo, std::string *nombre, int *cantidad, float *precio, std::string *ubicacionAlmacen);
void generarReporte(int *codigo, std::string *nombre, int *cantidad, float *precio, std::string  *ubicacionAlmacen);
void encontrarMasCaro(int *codigo, std::string *nombre, int *cantidad, float *precio, std::string  *ubicacionAlmacen);
void actualizarInventario(int *codigo, std::string *nombre, int *cantidad, float *precio, std::string  *ubicacionAlmacen);
void registrarNuevo(int *codigo, std::string *nombre, int *cantidad, float *precio, std::string  *ubicacionAlmacen);
void reporteBajoStock(int *codigo, std::string *nombre, int *cantidad, float *precio, std::string  *ubicacionAlmacen);
void encontrarMasBarato(int *codigo, std::string *nombre, int *cantidad, float *precio, std::string  *ubicacionAlmacen);
void guardarDatos(int *codigo, std::string *nombre, int *cantidad, float *precio, std::string  *ubicacionAlmacen);
void obtenerDatos(int *codigo, std::string *nombre, int *cantidad, float *precio, std::string  *ubicacionAlmacen);


int main() {
    
    // Iniciar Menú
    inicio();
    return 0;

}

// funcion principal que muestra el menu principal y la lista de opciónes para que el usuario elija también crea los arreglos paralelos que almacenan la información.
void inicio(){
    

    // arreglo codigo de producto
    int codigoProducto[100] = {

        // inicializacion de 5 productos minimo 

        100,
        101,
        102,
        103,
        104


    }; 

    // arreglo nombre del producto
    std::string nombreProducto[100] = {

        "Guantes de Cortes",
        "Cortadora Industrial para Fleje de Acero",
        "Candado de Aluminio para Bloqueo",
        "Pistola Engrapadora de Uso Manual",
        "Foco Led"


    }; 

    // arreglo cantidad en stock
    int cantidadStock[100] = {}; 

    // arreglo precio unitario
    float precioUnitario[100] = {}; 

    // arreglo de la ubicación del almacén
    std::string ubicacionAlmacen[100] = {};

    // obtener los datos y almacenarlos en los arreglos.
    obtenerDatos(codigoProducto, nombreProducto, cantidadStock, precioUnitario, ubicacionAlmacen); 

    // esta variable determinará si continuar el loop de la aplicación o no dependiendo de la elección del usuario.
    bool continuarEjecucion = true; 


    while(continuarEjecucion){

        int decision;

        std::cout << "\n-- Bienvenido al Sistema de Inventario de " << '"' << "El Martillo" << '"' << " --\n" << std::endl;
        std::cout << "Seleccione una opción:\n1. Consultar un producto\n2. Actualizar Inventario por Ubicación\n3. Registrar un nuevo producto\n4. Generar reporte completo\n5. Generar reporte de bajo stock\n6. Encontrar el producto más caro\n7. Encontrar el producto más barato\n8. Guardar y Salir" << std::endl;

        std::cin >> decision; // se espera el input del usuario.

        std::cout << "\nOpción seleccionada: " << decision << '\n' << std::endl; // mostrarle al usuario que elección seleccionó.

        switch (decision)
        {
            // si el usuario decidió consultar un producto.
            case 1:

                consultarProducto(codigoProducto, nombreProducto, cantidadStock, precioUnitario, ubicacionAlmacen);
                break;
        

            // si el usuario decidió actualizar el inventario.
            case 2:
                actualizarInventario(codigoProducto, nombreProducto, cantidadStock, precioUnitario, ubicacionAlmacen);
                break;

            // si el usuario decidió registrar un nuevo producto.
            case 3:
                registrarNuevo(codigoProducto, nombreProducto, cantidadStock, precioUnitario, ubicacionAlmacen);
                break;
            
            // si el usuario decidió generar reporte completo.
            case 4:
                generarReporte(codigoProducto, nombreProducto, cantidadStock, precioUnitario, ubicacionAlmacen);
                break;

            // si el usuario decide generar un reporte de bajo stock.
            case 5:
                reporteBajoStock(codigoProducto, nombreProducto, cantidadStock, precioUnitario, ubicacionAlmacen);
                break;

            // si el usuario decidió encontrar el producto más caro.
            case 6:
                encontrarMasCaro(codigoProducto, nombreProducto, cantidadStock, precioUnitario, ubicacionAlmacen);
                break;

            // si el usuario decide encontrar el numero mas barato.
            case 7:
                encontrarMasBarato(codigoProducto, nombreProducto, cantidadStock, precioUnitario, ubicacionAlmacen);
                break;

            // si el usuario decidió terminar el programa.
            case 8:

                guardarDatos(codigoProducto, nombreProducto, cantidadStock, precioUnitario, ubicacionAlmacen);
                std::cout << "Gracias por utilizar el Sistema de Inventario de El Martillo, Desarrollado por Mauricio Manzur" << std::endl;
                continuarEjecucion = false;
                break;

            // si no fue ninguna de estas opciones.
            default:
                std::cout << "Ingrese una opción válida\n" << std::endl;
                continuarEjecucion = false;
                break;
        }

    }

}

// funcion para consultar productos, le pide al usuario el codigo que quiere encontrar, y se lo muestra en pantalla.
void consultarProducto(int *codigo, std::string *nombre, int *cantidad, float *precio, std::string  *ubicacionAlmacen){

    int codigoABuscar = 0; // en esta varible se almacenará el codigo que el usuario determine para encontrar el producto.

    // esta variable booleana observará si un producto sí se llegó a encontrar con el codigo que estableció el usuario, en caso de que no, le muestra un mensaje de error claro. 
    bool siEncontro = false; 

    std::cout << "Ingrese el código del producto a consultar: ";
    std::cin >> codigoABuscar; // se espera input del usuario.

    // buscar en cada indice del arreglo codigo si el codigo a buscar coincide con él.
    for(int i = 0; i < cantidadInventario; i++){

        if(codigo[i] == codigoABuscar){

            // si se encontró el producto con el código especificado.
            siEncontro = true;

            // mostrar el codigo, nombre, cantidad de stock y precio unitario del producto que buscó el usuario.
            std::cout << "\nInformación del Producto:" << std::endl; 
            std::cout << "Código: " << codigo[i] << std::endl;
            std::cout << "Nombre: " << nombre[i] << std::endl;
            std::cout << "Cantidad en Stock: " << cantidad[i] << std::endl;
            std::cout << "Precio unitario: $" << precio[i] << std::endl;
            std::cout << "Ubicación Almacen: " << ubicacionAlmacen[i] << std::endl; 

        }


    }

    // al terminar el ciclo, verificar si la variable siEncontro terminó siendo true o false.
    if(!siEncontro){

        // mostrar mensaje de error si no se encontró el producto con ese codigo.
        std::cout << "\nNo se encontró el producto con el código: " << codigoABuscar << std::endl;

    }

}

// función para generar un reporte general con la información de todos los elementos del inventario de El Martillo.
void generarReporte(int *codigo, std::string *nombre, int *cantidad, float *precio, std::string  *ubicacionAlmacen){

    std::cout << "--- Reporte de Inventario ---" << std::endl;
    std::cout << "Código | Nombre                    | Stock | Precio | Ubicación Almacén" << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
    
    // mostrar todos los datos de cada elemento del inventario.
    for(int i = 0; i < cantidadInventario; i++){

        std::cout << codigo[i] << "    | " << nombre[i] << "            | " << cantidad[i] << " | $" << precio[i] << "| " << ubicacionAlmacen[i] << std::endl;

    }

    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "--- Fin del Reporte ---" << std::endl;


}

// funcion que encuentra el elemento más caro de todos en el arreglo.
void encontrarMasCaro(int *codigo, std::string *nombre, int *cantidad, float *precio, std::string  *ubicacionAlmacen){

    // esta variable representa el valor final de la cantidad encontrada (se espera que la variable almacene el precio más alto al final del ciclo)
    float buscadorMaximo = 0;

    for(int i = 0; i < cantidadInventario; i++){ // por cada precio de los elementos...

        for(int j = 0; j < cantidadInventario; j++){ // checar cada precio nuevamente y comparar el precio i con el precio j, y determinar

            /*
             * Esta condición primero observa si el precio a evaluar (i) es mayor a todos los precios que hay (j), en caso de que sí, 
             * pasamos a la siguiente condición, es buscadorMaximo < precio[j]? 
             * 
             * el propósito de la variable buscadorMáximo es que vaya almacenando el nuevo numéro máximo que se encuentre en cada ciclo,
             * supongamos que tengo un arreglo [10, 5, 20, 15] y hago dos ciclos: el ciclo (i), que en la primera repetición, i toma el valor de 10,
             * mientras que j tomará el valor de cada uno (aquí es donde evaluó si i = 10 es mayor a j = 10, j = 5, j = 20, j=15 y hasta que acabe).
             * 
             * supongamos, i = 10, es mayor a j = 5? entonces pasamos a la siguiente condición, el buscadorMáximo tiene que almacenar el valor más alto,
             * No puede almacenar un número menor que el que ya tiene, por lo tanto la siguiente condición: buscadorMáximo < precio[j], esto quiere decir
             * que el valor de buscadorMáximo será igual al valor de precio[j] si, y solo si, el valor de buscardorMáximo es menor.
             * 
             * Ejemplo:
             * i = 15; j = 10, j = 5, j = 20, j = 15; buscadorMáximo = 20;
             * 
             * i se encuentra en 15 y el buscadorMáximo se encuentra en 20, cuando se haga el ciclo, j checará todos los valores y j eventualmente se
             * topará con el valor 20, 20 es mayor a i = 15, pero como el valor del buscadorMáximo es 20, y se tiene que se cambiará el valor solo si buscadorMáximo
             * es menor, se va a saltar, dando como resultado: buscadorMáximo = 20, el cuál es viene siendo el más alto del vector.
             * 
             */


            if(precio[i] < precio[j] && buscadorMaximo < precio[j]){

                buscadorMaximo = precio[j]; // si el precio i (el que se busca evaluar) es mayor a precio j, entonces el valor de buscadorMaximo es el del precio que se evaluó

            }

        }

    }


    // al terminar el ciclo y encontrar el numéro máximo, hago otro ciclo para encontrar el elemento con el valor igual a buscadorMáximo
    for(int i = 0; i < cantidadInventario; i ++){

        if(precio[i] == buscadorMaximo){

            std::cout << "El producto más caro es: " << nombre[i] << " con un precio de $" << precio[i] << std::endl;            

        }

    }

}


// funcion que actualiza el stock del inventario.
void actualizarInventario(int *codigo, std::string *nombre, int *cantidad, float *precio, std::string  *ubicacionAlmacen){

    bool siEncontro = false; // esta variable determina si se encontró o no el producto por la ubicacion

    int indicePerteneciente = 0; // esta variable almacenará el indice del cual pertenece el objeto con la ubicacion dada.
    
    int numeroABuscar = 0; // en esta variable se almacenará el código que proporcione el usuario.

    std::string buscarUbicacion;

    std::cout << "\nIngrese la ubicación del producto a encontrar: ";
    std::cin.ignore();
    std::getline(std::cin, buscarUbicacion);

    for(int i = 0; i < cantidadInventario; i++){

        // si buscarUbicacion es igual a ubicacionAlmacen en el indice i
        if(buscarUbicacion.compare(ubicacionAlmacen[i]) == 0){

            siEncontro = true;
            indicePerteneciente = i; // asignamos el valor del indice que pertenece 

        }

    }

    // continuar con el siguiente paso en caso de si haberse encontrado el elemento.
    if(siEncontro){

        int nuevoStock = 0;

        std::cout << "\nIngrese la cantidad a agregar/quitar(+/-): ";
        std::cin >> nuevoStock;
        
        cantidad[indicePerteneciente] += nuevoStock;

        std::cout << "\nCantidad actualizada exitosamente. El nuevo stock de " << nombre[indicePerteneciente] <<"  es " << cantidad[indicePerteneciente] << "." << std::endl;


    }

    // si no se llego a encontrar un elemento en la lista, mostrar un mensaje de error.
    else{

        std::cout << "\nNo se encontró el elemento con ubicación: " << buscarUbicacion << std::endl; 

    }

}

// funcion para registrar un nuevo producto en la lista
void registrarNuevo(int *codigo, std::string *nombre, int *cantidad, float *precio, std::string *ubicacionAlmacen){

    bool codigoRepetido = false;
    int confirmarProducto = 0; 

    int codigoNuevo;
    std::string nombreNuevo;
    int stockNuevo;
    float precioNuevo;
    std::string ubicacionNuevo;


    std::cout << "\nRegistrar un nuevo producto:\n" << std::endl;
    std::cout << "¿Cuál es el código del producto?" << std::endl;
    std::cin >> codigoNuevo;

    for(int i = 0; i < cantidadInventario; i++){

        if(codigoNuevo == codigo[i]){

            codigoRepetido = true;

        }

    }

    if(codigoRepetido){

        std::cout << "\nEl código " << codigoNuevo << " ya se ecuentra tomado por otro producto, no se aplicará la operación." << std::endl;

    }

    else{

        std::cout << "¿Cuál es el nombre del producto?" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, nombreNuevo);

        std::cout << "¿Cuál es el stock inicial del producto?" << std::endl;
        std::cin >> stockNuevo;
        std::cin.ignore();


        std::cout << "¿Cuál es el precio unitario del producto?" << std::endl;
        std::cin >> precioNuevo;
        std::cin.ignore();


        std::cout << "¿Cuál es el código del almacen en el que se encuentra ubicado?" << std::endl;
        std::getline(std::cin, ubicacionNuevo);



        std::cout << "\nInformación previsualizadora:\nCódigo: " << codigoNuevo << "\nNombre: " << nombreNuevo << "\nStock: " << stockNuevo << "\nPrecio Unitario: " << precioNuevo << "\nUbicación Almacén: " << ubicacionNuevo << std::endl;
        
        std::cout << "\n\n¿Aceptas el nuevo producto?\n1. Si\n2. No" << std::endl;
        std::cin >> confirmarProducto;
        std::cin.ignore();


        switch (confirmarProducto)
        {
            case 1:

                // si el usuario esta de acuerdo con el nuevo producto, entonces agregarlo al arreglo.

                // la variable cantidadInventario almacena la cantidad de elementos que se encuentran en arreglo, siguiendo con la lógica
                // donde los indices son = al tamaño - 1, agregar un elemento al ultimo indice es 4 y cantidadInventario = cantidad de elementos = 5, entonces cantidadInventario se agregarn los elementos nuevos.


                codigo[cantidadInventario] = codigoNuevo;
                nombre[cantidadInventario] = nombreNuevo;
                cantidad[cantidadInventario] = stockNuevo;
                precio[cantidadInventario] = precioNuevo;
                ubicacionAlmacen[cantidadInventario] = ubicacionNuevo;

                cantidadInventario++;


                std::cout << "Se han agregado los elementos correctamente." << std::endl; 
                break;

            case 2:
                std::cout << "\nCancelando operación" << std::endl;
                break;

        
            default:
                std::cout << "\nIngrese una opción válida" << std::endl;
                break;
        }

    }
    

}

// función que genera un reporte de todos los productos en un bajo umbral predefinido.
void reporteBajoStock(int *codigo, std::string *nombre, int *cantidad, float *precio, std::string  *ubicacionAlmacen){

    int umbralDefinido = 0;

    std::cout << "\nIngrese el umbral numérico para listar los productos: ";
    std::cin >> umbralDefinido;

    std::cout << "--- Reporte de Inventario ( stock menor a " << umbralDefinido << ") ---" << std::endl;
    std::cout << "Código | Nombre                    | Stock | Precio | Ubicación Almacén" << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
    

    for(int i = 0; i < cantidadInventario; i++){

        if(cantidad[i] < umbralDefinido){

            std::cout << codigo[i] << " | " << nombre[i] << " | " << cantidad[i] << " | " << precio[i] << " | " << ubicacionAlmacen[i] << std::endl;

        }

    }

}

// funcion que encuentra el producto más barato.

void encontrarMasBarato(int *codigo, std::string *nombre, int *cantidad, float *precio, std::string  *ubicacionAlmacen){

    // ** siguiendo el mismo principio de la funcion encontrarMasCaro, pero al reves... **

    float buscadorMinimo = 500000; // este valor es un ejemplo.

    for(int i = 0; i < cantidadInventario; i++){

        for(int j = 0; j < cantidadInventario; j++){

            if(precio[i] > precio[j] && buscadorMinimo > precio[j]){

                buscadorMinimo = precio[j];

            }

        }

    }

    for(int i = 0; i < cantidadInventario; i ++){

        if(precio[i] == buscadorMinimo){

            std::cout << "El producto más barato es: " << nombre[i] << " con un precio de $" << precio[i] << std::endl;            

        }

    }    

}

// funcion para guardar los datos en un archivo 
void guardarDatos(int *codigo, std::string *nombre, int *cantidad, float *precio, std::string  *ubicacionAlmacen){


    std::ofstream archivo("guardado.txt");

    if(archivo.is_open()){

        for(int i = 0; i < cantidadInventario; i++){

            archivo << codigo[i] << "," << nombre[i] << "," << cantidad[i] << "," << precio[i] << "," << ubicacionAlmacen[i] << std::endl;

        }

    }

}

// funcion para obtener los datos del archivo de guardado.txt
void obtenerDatos(int *codigo, std::string *nombre, int *cantidad, float *precio, std::string  *ubicacionAlmacen){


    std::cout << "\nCargando inventario desde " << "'" << "guardado.txt" << "'" << std::endl; 

    std::ifstream archivo("guardado.txt");

    std::string dato; // almacena la cadena entera antes del \n, ejemplo: codigo,nombre,cantidad,precio,ubicacionAlmacen.

    int indiceGuardian[4] = {}; // almacena los indices de cada coma en la cadena dato.


    if(!archivo.is_open()){

        std::cout << "\nNo se pudieron cargar los datos del archivo de guardado." << std::endl;

    }

    else{

        while(std::getline(archivo, dato)){

            int contador = 0;

            for(long unsigned int i = 0; i < dato.length(); i++){

                if(dato[i] == ','){

                    indiceGuardian[contador] = i; // guardar el indice en donde se encuentra ',' en el arreglo indiceGuardian[i].
                    contador++;

                }

            }

            // quebrar las cadenas en partes basandose en los indices de las comas en indiceGuardian.
            std::string codigoEncontrado = dato.substr(0, indiceGuardian[0]);
            std::string nombreEncontrado = dato.substr(indiceGuardian[0]+1, indiceGuardian[1]-1 - indiceGuardian[0]);
            std::string cantidadEncontrado = dato.substr(indiceGuardian[1]+1, indiceGuardian[2]-1 - indiceGuardian[1]);
            std::string precioEncontrado = dato.substr(indiceGuardian[2]+1, indiceGuardian[3]-1 - indiceGuardian[2]);
            std::string ubicacionEncontrado = dato.substr(indiceGuardian[3]+1);


            try{
                
                // agregar todos los elementos en el indice cantidadInventarios que aumenta al asignar todos sus valores
                // std::stoi me permite convertir una cadena de texto en entero, std::stof permite cambiar una cadena en float.
                codigo[cantidadInventario] = std::stoi(codigoEncontrado);
                nombre[cantidadInventario] = nombreEncontrado;
                cantidad[cantidadInventario] = std::stoi(cantidadEncontrado);
                precio[cantidadInventario] = std::stof(precioEncontrado);
                ubicacionAlmacen[cantidadInventario] = ubicacionEncontrado;
                    
                cantidadInventario++;

            }

            catch(std::exception &e){

                std::cout << "\nHubo un error con la obtención de los datos: " << e.what() << std::endl;

            }

        }

        if(cantidadInventario > 0){

            std::cout << "Inventario cargado exitosamente. " << cantidadInventario << " productos encontrados." << std::endl;

        }
        else{

            std::cout << "No se encontraron productos en el archivo de guardado.txt" << std::endl;

        }
        
    }


}
