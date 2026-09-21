#ifndef mapa_h
#define mapa_h

#include "inicializador.h"

Mapa crearMapa(int linea, int columna);

bool posicionValida(const Mapa& mapa, Punto p);

bool esObstaculo(const Mapa& mapa, Punto p);

void setInicio(Mapa& mapa, Punto p);

void setMeta(Mapa& mapa, Punto p);

void setObstaculos(Mapa& mapa, Punto p);

vector<Punto> getVecinos(const Mapa& mapa, Punto p);

void imprimir_mapa(const Mapa& mapa, 
    const vector<vector<bool>>& vistos = {}, 
    const vector<Punto>& camino = {} 
);

bool guardarMapa(const Mapa& mapa, const string& archivo);

bool cargarMapa(Mapa& mapa, const string& archivo);

#endif



