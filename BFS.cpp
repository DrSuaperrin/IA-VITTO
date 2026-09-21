#include "BFS.h"
#include "Mapa.h"
#include "Utilidades.h"

#include <queue>
#include <algorithm>

using namespace std;

Resultado_Busqueda BFS(const Mapa& mapa){

    Resultado_Busqueda resultado;

    resultado.encontrado = false;

    resultado.pasos = 0;

    int fila = mapa.fila;
    int columna = mapa.columna;

    Punto inicio = mapa.inicio;
    Punto meta = mapa.meta;

    vector<vector<bool>> vistos = crearVistos(fila,columna);

    vector<vector<Punto>> parientes(fila, vector<Punto>(columna,{-1,-1}));

    queue<Punto> cola;

    cola.push(inicio);

    vistos[inicio.fila][inicio.columna] = true;

    while(!cola.empty()){

        Punto actual = cola.front();

        cola.pop();

        resultado.pasos++;

        mostrarPasos(mapa, vistos, actual, resultado.pasos);

        if(actual == meta){

            resultado.encontrado = true;

            resultado.camino = reconstruirCamino(parientes, inicio, meta);

            return resultado;

        }

        vector<Punto> vecinos = getVecinos(mapa, actual);

        for(Punto sig : vecinos){

            if(!vistos[sig.fila][sig.columna]){

                vistos[sig.fila][sig.columna] = true;

                parientes[sig.fila][sig.columna] = actual;

                cola.push(sig);

            }

        }

    }

    return resultado;

}