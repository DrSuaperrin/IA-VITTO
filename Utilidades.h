#ifndef utilidades_h
#define utilidades_h

#include "Inicializador.h"

int manhattan(Punto a, Punto b);

vector<vector<bool>> crearVistos(int fila, int columna);

vector<Punto> reconstruirCamino(const vector<vector<Punto>> parientes, Punto inicio, Punto meta);

void mostrarPasos(const Mapa& mapa, const vector<vector<bool>>& vistos, Punto actual, int pasos);

void mostrarResultado(const Mapa& mapa, const Resultado_Busqueda& resultado);

#endif