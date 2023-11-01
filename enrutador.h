#ifndef ENRUTADOR_H
#define ENRUTADOR_H

#include <string>
#include <map>
using namespace std;

class Enrutador {
private:
    string nombre;
   map<string, int> tabla_de_enrutamiento; // Destino -> Costo

public:
    Enrutador(const string& nombre);

    const string& obtenerNombre() const;

    void actualizarTablaDeEnrutamiento(const string& destino, int costo);

    void removerConexion(const string& destino);

    int obtenerCostoHacia(const string& destino) const;

    const map<string, int>& obtenerTablaDeEnrutamiento() const;
};

#endif
