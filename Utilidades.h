#ifndef utilidades.h
#define utilidades.h

#include "inicializador.h"

int manhattan(Punto a, Punto b);

vector<vector<bool>> crearVistos(int fila, int columna);

vector<Punto> reconstruirCamino(const vector<vector<Punto>> parientes, Punto inicio, Punto meta);

void mostrarPasos(const Mapa& mapa, const vector<vector<bool>>& vistos, Punto actual, int pasos);

void mostrarResultado(const Mapa& mapa, const BuscarResultado& resultado);

#endif