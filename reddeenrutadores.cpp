#include "RedDeEnrutadores.h"
#include <iostream>
#include <set>
#include <fstream>
#include <sstream>

using namespace std;

void RedDeEnrutadores::agregarEnrutador(const string& nombre) {
    enrutadores.emplace_back(nombre);
}

void RedDeEnrutadores::actualizarConexion(const string& origen, const string& destino, int costo) {
    if (costo >= 1) {
        for (auto& enrutador : enrutadores) {
            if (enrutador.obtenerNombre() == origen) {
                enrutador.actualizarTablaDeEnrutamiento(destino, costo);
            }
        }
    } else {
        cout << "Error: El costo debe ser un entero no menor de 1." << endl;
    }
}

void RedDeEnrutadores::removerConexion(const string& origen, const string& destino) {
    for (auto& enrutador : enrutadores) {
        if (enrutador.obtenerNombre() == origen) {
            enrutador.removerConexion(destino);
        }
    }
}

int RedDeEnrutadores::costoDeEnvio(const string& origen, const string& destino) {
    for (auto& enrutador : enrutadores) {
        if (enrutador.obtenerNombre() == origen) {
            return enrutador.obtenerCostoHacia(destino);
        }
    }
    return INT_MAX;
}

vector<string> RedDeEnrutadores::encontrarRutaMasCorta(const string& origen, const string& destino) {
        // Crear un conjunto de enrutadores no visitados
        set<string> no_visitados;

        // Crear una tabla de distancias y una tabla de rutas
        map<string, int> distancia;
        map<string, string> ruta;

        // Inicializar distancias con infinito y rutas vacías
        for (const Enrutador& enrutador : enrutadores) {
            const string nombre = enrutador.obtenerNombre();
            distancia[nombre] = INT_MAX;
            ruta[nombre] = "";
            no_visitados.insert(nombre);
        }

        // La distancia del nodo de origen a sí mismo es 0
        distancia[origen] = 0;

        while (!no_visitados.empty()) {
            // Encontrar el enrutador con la distancia mínima
            string enrutador_actual;
            int distancia_minima = INT_MAX;
            for (const string& enrutador : no_visitados) {
                if (distancia[enrutador] < distancia_minima) {
                    enrutador_actual = enrutador;
                    distancia_minima = distancia[enrutador];
                }
            }

            // Eliminar el enrutador actual de los no visitados
            no_visitados.erase(enrutador_actual);

            // Actualizar las distancias a los vecinos del enrutador actual
            for (const Enrutador& vecino : enrutadores) {
                const string nombre_vecino = vecino.obtenerNombre();
                if (no_visitados.count(nombre_vecino) > 0) {
                    int distancia_alternativa = distancia[enrutador_actual] + vecino.obtenerCostoHacia(nombre_vecino);
                    if (distancia_alternativa < distancia[nombre_vecino]) {
                        distancia[nombre_vecino] = distancia_alternativa;
                        ruta[nombre_vecino] = enrutador_actual;
                    }
                }
            }
        }

        // Reconstruir la ruta desde el destino hasta el origen
        vector<string> ruta_mas_corta;
        string enrutador_actual = destino;
        while (enrutador_actual != "" && ruta[enrutador_actual] != "") {
            ruta_mas_corta.insert(ruta_mas_corta.begin(), enrutador_actual);
            enrutador_actual = ruta[enrutador_actual];
        }

        return ruta_mas_corta;
    }



void RedDeEnrutadores::cargarDesdeArchivo(const string& archivo) {
    // Implementa la lógica para cargar la topología de la red desde un archivo.
        ifstream file(archivo);

        if (file.is_open()) {
            string linea;
            while (getline(file, linea)) {
                string origen, destino;
                int costo;
                istringstream ss(linea);
                ss >> origen >> destino >> costo;
                actualizarConexion(origen, destino, costo);
            }

            file.close();
           cout << "Topología cargada desde el archivo: " << archivo << endl;
        } else {
            cerr << "Error al abrir el archivo: " << archivo << endl;
        }
}
void RedDeEnrutadores::mostrarConexiones() {
        for (const Enrutador& enrutador : enrutadores) {
            cout << "Conexiones desde " << enrutador.obtenerNombre() << ":\n";
            const map<string, int>& tabla = enrutador.obtenerTablaDeEnrutamiento();
            for (const auto& par : tabla) {
                cout << "  " << par.first << " -> " << par.second << "\n";
            }
        }
}

