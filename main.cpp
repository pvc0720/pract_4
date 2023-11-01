#include <iostream>
#include "RedDeEnrutadores.h"
#include "enrutador.h"
using namespace std;
int main() {
    RedDeEnrutadores red;

    red.agregarEnrutador("A");
    red.agregarEnrutador("B");
    red.agregarEnrutador("C");
    red.agregarEnrutador("D");

    int opcion;

    do {
        cout << "Menu de opciones:\n";
        cout << "1. Agregar conexion\n";
            std::cout << "2. Eliminar conexion\n";
            std::cout << "3. Cargar topologia desde archivo\n";
            std::cout << "4. Encontrar ruta mas corta\n";
            std::cout << "5. Mostrar conexiones existentes\n";
        std::cout << "0. Salir\n";
        std::cout << "Elija una opcion: ";
                std::cin >> opcion;

        switch (opcion) {
        case 1: {
            // Agregar conexión
            std::string origen, destino;
            int costo;
            std::cout << "Ingrese el enrutador de origen: ";
            std::cin >> origen;
            std::cout << "Ingrese el enrutador de destino: ";
            std::cin >> destino;
            std::cout << "Ingrese el costo: ";
            std::cin >> costo;
            red.actualizarConexion(origen, destino, costo);
            break;
        }
        case 2: {
            // Eliminar conexión
            std::string origen, destino;
            std::cout << "Ingrese el enrutador de origen: ";
            std::cin >> origen;
            std::cout << "Ingrese el enrutador de destino: ";
            std::cin >> destino;
            red.removerConexion(origen, destino);
            break;
        }
        case 3: {
            // Cargar topología desde archivo
            std::string archivo;
            std::cout << "Ingrese el nombre del archivo de topología: ";
                    std::cin >> archivo;
            red.cargarDesdeArchivo(archivo);
            break;
        }
        case 4: {
            // Encontrar ruta más corta
            std::string origen, destino;
            std::cout << "Ingrese el enrutador de origen: ";
            std::cin >> origen;
            std::cout << "Ingrese el enrutador de destino: ";
            std::cin >> destino;
            std::vector<std::string> ruta_mas_corta = red.encontrarRutaMasCorta(origen, destino);

            if (ruta_mas_corta.empty()) {
                std::cout << "No se encontró una ruta desde " << origen << " a " << destino << "." << std::endl;
            } else {
                std::cout << "Ruta más corta desde " << origen << " a " << destino << ": ";
                    for (const std::string& enrutador : ruta_mas_corta) {
                    std::cout << enrutador << " -> ";
                }
                std::cout << "Costo total: " << red.costoDeEnvio(origen, destino) << std::endl;
            }
            break;
        }
        case 5: {
            // Mostrar conexiones existentes
            red.mostrarConexiones();
            break;
        }
        case 0:
            std::cout << "Saliendo del programa." << std::endl;
            break;
        default:
            std::cout << "Opcion no valida. Intentelo de nuevo." << std::endl;
        }
    } while (opcion != 0);

    return 0;
}

