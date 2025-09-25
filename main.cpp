#include <iostream>


// esta variable guardián establece cuantos elementos hay actualmente en los arreglos (sirve para hacer los ciclos for menos pesados)
int cantidadInventario = 5;

// defino el prototipo de las funciones de la aplicación
void inicio();
void consultarProducto(int *codigo, std::string *nombre, int *cantidad, float *precio);
void generarReporte(int *codigo, std::string *nombre, int *cantidad, float *precio);
void encontrarMasCaro(int *codigo, std::string *nombre, int *cantidad, float *precio);
void actualizarInventario(int *codigo, std::string *nombre, int *cantidad, float *precio);


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
    int cantidadStock[100] = {

        10,
        5,
        35,
        15,
        28


    }; 

    // arreglo precio unitario
    float precioUnitario[100] = {

        612.48,
        1607.76,
        1224.96,
        1122.88,
        150.00

    }; 

    // esta variable determinará si continuar el loop de la aplicación o no dependiendo de la elección del usuario.
    bool continuarEjecucion = true; 


    while(continuarEjecucion){

        int decision;

        std::cout << "\n-- Bienvenido al Sistema de Inventario de " << '"' << "El Martillo" << '"' << " --\n" << std::endl;
        std::cout << "Seleccione una opción:\n1. Consultar un producto\n2. Actualizar Inventario\n3. Generar reporte completo\n4. Encontrar el producto más caro\n5. Salir" << std::endl;

        std::cin >> decision; // se espera el input del usuario.

        std::cout << "\nOpción seleccionada: " << decision << '\n' << std::endl; // mostrarle al usuario que elección seleccionó.

        switch (decision)
        {
            // si el usuario decidió consultar un producto.
            case 1:

                consultarProducto(codigoProducto, nombreProducto, cantidadStock, precioUnitario);
                break;
        

            // si el usuario decidió actualizar el inventario.
            case 2:
                actualizarInventario(codigoProducto, nombreProducto, cantidadStock, precioUnitario);
                break;
            
            // si el usuario decidió generar reporte completo.
            case 3:
                generarReporte(codigoProducto, nombreProducto, cantidadStock, precioUnitario);
                break;

            // si el usuario decidió encontrar el producto más caro.
            case 4:
                encontrarMasCaro(codigoProducto, nombreProducto, cantidadStock, precioUnitario);
                break;

            // si el usuario decidió terminar el programa.
            case 5:
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
void consultarProducto(int *codigo, std::string *nombre, int *cantidad, float *precio){

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



        }


    }

    // al terminar el ciclo, verificar si la variable siEncontro terminó siendo true o false.
    if(!siEncontro){

        // mostrar mensaje de error si no se encontró el producto con ese codigo.
        std::cout << "\nNo se encontró el producto con el código: " << codigoABuscar << std::endl;

    }

}

// función para generar un reporte general con la información de todos los elementos del inventario de El Martillo.
void generarReporte(int *codigo, std::string *nombre, int *cantidad, float *precio){

    std::cout << "--- Reporte de Inventario ---" << std::endl;
    std::cout << "Código | Nombre                    | Stock | Precio" << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
    
    // mostrar todos los datos de cada elemento del inventario.
    for(int i = 0; i < cantidadInventario; i++){

        std::cout << codigo[i] << "    | " << nombre[i] << "            | " << cantidad[i] << " | $" << precio[i] << std::endl;

    }

    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "--- Fin del Reporte ---" << std::endl;


}

// funcion que encuentra el elemento más caro de todos en el arreglo.
void encontrarMasCaro(int *codigo, std::string *nombre, int *cantidad, float *precio){

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
void actualizarInventario(int *codigo, std::string *nombre, int *cantidad, float *precio){
    
    int numeroABuscar = 0; // en esta variable se almacenará el código que proporcione el usuario.

    int indiceEncontrado = 0; // esta variable almacena el indice en donde se encuentra el elemento con el código que el usuario especificó

    bool siEncontro = false; // esta variable cambiará a true siempre y cuando si se encuentre el item.


    std::cout << "Ingrese el código del producto a actualizar: ";
    std::cin >> numeroABuscar; // se espera input de usuario.

    // verificar si el codigo existe.
    for(int i = 0; i < cantidadInventario; i ++){

        if(numeroABuscar == codigo[i]){

            indiceEncontrado = i; // guardamos el indice en donde se encuentra el codigo.
            siEncontro = true;
            break;

        }

    }

    // continuar con el siguiente paso en caso de si haberse encontrado el elemento.
    if(siEncontro){

        int cantidadStock = 0; // esta variable guardará la cantidad de stock que el usuario decida actualizar del producto.

        std::cout << "\nDetermina el stock del producto " << nombre[indiceEncontrado] << ": "; 
        std::cin >> cantidadStock; // se espera input de usuario.

        if(cantidadStock < 0){

            std::cout << "\nNo se permite una cantidad menor a 0, no se aplicará el nuevo cambio.\n" << std::endl;

        }

        else{

            cantidad[indiceEncontrado] = cantidadStock;
            std::cout << "\nSe asignó la cantidad de: " << cantidadStock << " al producto " << nombre[indiceEncontrado] << "\n" << std::endl;

        }

    }

    // si no se llego a encontrar un elemento en la lista, mostrar un mensaje de error.
    else{

        std::cout << "\nNo se encontró el elemento con código: " << numeroABuscar << std::endl; 

    }




}