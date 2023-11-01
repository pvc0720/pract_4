#ifndef REDDEENRUTADORES_H
#define REDDEENRUTADORES_H

#include <vector>
#include <string>
#include <map>
#include "Enrutador.h"
using namespace std;
class RedDeEnrutadores {
private:
    vector<Enrutador> enrutadores;

public:
    void agregarEnrutador(const string& nombre);

    void actualizarConexion(const string& origen, const string& destino, int costo);

    void removerConexion(const string& origen, const string& destino);

    int costoDeEnvio(const string& origen, const std::string& destino);

    std::vector<std::string> encontrarRutaMasCorta(const std::string& origen, const std::string& destino);

    void cargarDesdeArchivo(const std::string& archivo);

     void mostrarConexiones();

    const std::vector<Enrutador>& obtenerEnrutadores() const;

};

#endif
