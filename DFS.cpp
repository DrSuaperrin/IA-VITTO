#include "DFS.h"
#include "Mapa.h"
#include "Utilidades.h"

#include <stack>
#include <algorithm>

using namespace std;

Resultado_Busqueda DFS(const Mapa& mapa)
{
    Resultado_Busqueda resultado;

    resultado.encontrado = false;
    resultado.pasos = 0;

    int fila = mapa.fila;
    int columna = mapa.columna;

    Punto inicio = mapa.inicio;
    Punto meta = mapa.meta;

    vector<vector<bool>> vistos = crearVistos(fila, columna);

    vector<vector<Punto>> parientes(fila, vector<Punto>(columna,{-1, -1}));

    stack<Punto> pila;

    pila.push(inicio);

    while (!pila.empty())
    {
        Punto actual = pila.top();

        pila.pop();

        if (vistos[actual.fila][actual.columna]) continue;

        vistos[actual.fila][actual.columna] = true;

        resultado.pasos++;

        mostrarPasos(mapa, vistos, actual, resultado.pasos);

        if (actual == meta){

            resultado.encontrado = true;

            resultado.camino =  reconstruirCamino(parientes, inicio, meta);

            return resultado;

        }

        vector<Punto> vecinos = getVecinos(mapa,actual);

        reverse( vecinos.begin(), vecinos.end());

        for (Punto siguiente : vecinos)
        {
            if (!vistos[siguiente.fila][siguiente.columna]){

                parientes[siguiente.fila][siguiente.columna] = actual;

                pila.push(siguiente);

            }
        }
    }

    return resultado;
}
