#include "Enrutador.h"
#include <iostream>

using namespace std;

Enrutador::Enrutador(const string& nombre) : nombre(nombre) {}

const string& Enrutador::obtenerNombre() const {
    return nombre;
}

void Enrutador::actualizarTablaDeEnrutamiento(const string& destino, int costo) {
    tabla_de_enrutamiento[destino] = costo;
}

void Enrutador::removerConexion(const string& destino) {
    tabla_de_enrutamiento.erase(destino);
}

int Enrutador::obtenerCostoHacia(const string& destino) const {
    auto it = tabla_de_enrutamiento.find(destino);
    if (it != tabla_de_enrutamiento.end()) {
        return it->second;
    } else {
        return INT_MAX;
    }
}

const map<string, int>& Enrutador::obtenerTablaDeEnrutamiento() const {
    return tabla_de_enrutamiento;
}
