#include "Utilidades.h"
#include "Mapa.h"

#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

const int DELAY_MS = 150;

int manhattan(Punto a, Punto b){
    return (abs(a.fila - b.fila) + abs(a.columna - b.columna));
}

vector<vector<bool>> crearVistos(int fila, int columna){
    return vector<vector<bool>>(fila, vector<bool>(columna,false));
}

vector<Punto> reconstruirCamino(const vector<vector<Punto>> parientes, 
Punto inicio, 
Punto meta){

    vector<Punto> camino;

    Punto actual = meta;

    while(!(actual == inicio)){

        camino.push_back(actual);

        Punto anterior = parientes[actual.fila][actual.columna];

        if(anterior.fila == -1) return {};

        actual = anterior;

    }

    camino.push_back(inicio);

    reverse(camino.begin(), camino.end());

    return camino;

}

void mostrarPasos(const Mapa& mapa, const vector<vector<bool>>& vistos, 
Punto actual, 
int pasos){

    imprimir_mapa(mapa, vistos);

    cout<<'\n';
    cout<<"Nodo actual: ("<<actual.fila<<", "<<actual.columna<<")\n";
    cout<<"Pasos de busqueda: "<<pasos<< "\n";

    cout << "\nPresiona ENTER para continuar...";

    // Limpiar el ENTER que quedó del cin >> 
    cin.ignore(
        numeric_limits<streamsize>::max(),
        '\n'
    );

    cin.get();

}

void mostrarResultado(
    const Mapa& mapa,
    const Resultado_Busqueda& resultado
)
{
    cout << "\n";
    cout << "========================================\n";
    cout << "               RESULTADO\n";
    cout << "========================================\n";

    // --------------------------------------------------------
    // NO SE ENCONTRO CAMINO
    // --------------------------------------------------------

    if (!resultado.encontrado)
    {
        cout<<"No se encontro un camino.\n";
        cout<<"Total de pasos de busqueda: "<< resultado.pasos<< "\n";

        return;
    }

    // --------------------------------------------------------
    // SE ENCONTRO CAMINO
    // --------------------------------------------------------

    cout<<"Camino encontrado.\n";
    cout<<"Longitud del camino: "<<resultado.camino.size() - 1<< "\n";
    cout<<"Total de pasos de busqueda: "<< resultado.pasos<< "\n";

    // --------------------------------------------------------
    // MOSTRAR CAMINO
    // --------------------------------------------------------

    cout << "\nCamino:\n";

    for (size_t i = 0;i < resultado.camino.size();i++){

        cout <<"("<<resultado.camino[i].fila<<", "<< resultado.camino[i].columna<<")";

        if (i + 1 < resultado.camino.size()) cout<<" -> ";

    }

    cout << "\n\n";

    // --------------------------------------------------------
    // MOSTRAR MAPA CON EL CAMINO
    // --------------------------------------------------------

    imprimir_mapa(
        mapa,
        {},
        resultado.camino
    );

    cout << "\n";
    cout << "Presiona ENTER para continuar...";

    cin.ignore(
        numeric_limits<streamsize>::max(),
        '\n'
    );

    cin.get();
}