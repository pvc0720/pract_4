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
            cout << "2. Eliminar conexion\n";
            cout << "3. Cargar topologia desde archivo\n";
            cout << "4. Encontrar ruta mas corta\n";
            cout << "5. Mostrar conexiones existentes\n";
            cout << "0. Salir\n";
        cout << "Elija una opcion: ";
              cin >> opcion;

        switch (opcion) {
        case 1: {
            // Agregar conexión
            string origen, destino;
            int costo;
            cout << "Ingrese el enrutador de origen: ";
            cin >> origen;
            cout << "Ingrese el enrutador de destino: ";
            cin >> destino;
            cout << "Ingrese el costo: ";
            cin >> costo;
            red.actualizarConexion(origen, destino, costo);
            break;
        }
        case 2: {
            // Eliminar conexión
            string origen, destino;
            cout << "Ingrese el enrutador de origen: ";
            cin >> origen;
            cout << "Ingrese el enrutador de destino: ";
            cin >> destino;
            red.removerConexion(origen, destino);
            break;
        }
        case 3: {
            // Cargar topología desde archivo
            string archivo;
            cout << "Ingrese el nombre del archivo de topología: ";
            cin >> archivo;
            red.cargarDesdeArchivo(archivo);
            break;
        }
        case 4: {
            // Encontrar ruta más corta
            string origen, destino;
            cout << "Ingrese el enrutador de origen: ";
            cin >> origen;
            cout << "Ingrese el enrutador de destino: ";
            cin >> destino;
            vector<string> ruta_mas_corta = red.encontrarRutaMasCorta(origen, destino);

            if (ruta_mas_corta.empty()) {
                cout << "No se encontró una ruta desde " << origen << " a " << destino << "." << endl;
            } else {
                cout << "Ruta más corta desde " << origen << " a " << destino << ": ";
                    for (const string& enrutador : ruta_mas_corta) {
                    cout << enrutador << " -> ";
                }
                cout << "Costo total: " << red.costoDeEnvio(origen, destino) << endl;
            }
            break;
        }
        case 5: {
            // Mostrar conexiones existentes
            red.mostrarConexiones();
            break;
        }
        case 0:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opcion no valida. Intentelo de nuevo." << endl;
        }
    } while (opcion != 0);

    return 0;
}

