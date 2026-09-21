#ifndef inicializador_h
#define inicializador_h

#include <vector>

using namespace std;

//En lugar de vector de pares utilizamos Punto como una instancia de coordenadas.
struct Punto{

//Coordenadas.
    int fila;
    int columna;

//Esta funcion convierte el operador para comparar instancias de tipo Punto.
    bool operator == (const Punto& otro) const{
        return ((fila == otro.fila) && (columna == otro.columna));
    }

};

//Guarda el resultado de la busqueda, al igual si fue posible o no.
struct Resultado_Busqueda{

    bool encontrado;

    vector<Punto> camino;

    int pasos;

};


struct Mapa{

    int fila;
    int columna;

    vector<vector<char>> grid;

    Punto inicio;
    Punto meta;

};

#endif
