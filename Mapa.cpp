#include "Mapa.h"

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const char VACIO = '.';
const char OBSTACULO = '#';
const char INICIO = 'S';
const char META = 'G';
const char VISTO = 'x';
const char CAMINO = 'o';

Mapa crearMapa(int fila, int columna){

    Mapa mapa;

    mapa.fila = fila;

    mapa.columna = columna;

    mapa.grid.assign(fila, vector<char>(columna,VACIO));

    mapa.inicio = {-1, -1};

    mapa.meta = {-1, -1};

    return mapa;

}

bool posicionValida(const Mapa& mapa, Punto p){

    return p.fila >= 0 
    && p.fila < mapa.fila 
    && p.columna >= 0 
    && p.columna < mapa.columna;

}

bool esObstaculo(const Mapa& mapa, Punto p){

    return mapa.grid[p.fila][p.columna] == OBSTACULO;

}

void setInicio(Mapa& mapa, Punto p){

    if(!posicionValida(mapa, p)) return;

    if(esObstaculo(mapa, p)) return;

    if(posicionValida(mapa, mapa.inicio)){

        mapa.grid[mapa.inicio.fila][mapa.inicio.columna] = VACIO;

    }

    mapa.inicio = p;

    mapa.grid[p.fila][p.columna] = INICIO;

}

void setMeta(Mapa& mapa, Punto p){

    if(!posicionValida(mapa, p)) return;

    if(esObstaculo(mapa, p)) return;

    if(posicionValida(mapa, mapa.meta)){

        mapa.grid[mapa.meta.fila][mapa.meta.columna] = VACIO;

    }

    mapa.meta = p;

    mapa.grid[p.fila][p.columna] = META;

}

void setObstaculos(Mapa& mapa, Punto p){

    if(!posicionValida(mapa, p)) return;

    if(p == mapa.inicio || p == mapa.meta) return;

    if(mapa.grid[p.fila][p.columna] == OBSTACULO) mapa.grid[p.fila][p.columna] = VACIO;
    else mapa.grid[p.fila][p.columna] = OBSTACULO;

}

vector<Punto> getVecinos(const Mapa& mapa, Punto p){

    vector<Punto> vecinos;

    Punto arriba{
        p.fila - 1, p.columna
    };

    Punto abajo{
        p.fila + 1, p.columna
    };

    Punto derecha{
        p.fila, p.columna + 1
    };

    Punto izquierda{
        p.fila, p.columna - 1
    };

    vector<Punto> posibles = {
        arriba,
        derecha,
        abajo,
        izquierda
    };

    for(Punto sig : posibles){
        if(posicionValida(mapa, sig) && !esObstaculo(mapa,sig)) vecinos.push_back(sig);
    }

    return vecinos;

}

void imprimir_mapa(const Mapa& mapa, const vector<vector<bool>>& vistos, const vector<Punto>& camino ){

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif


    vector<vector<char>> display = mapa.grid;

    if(!vistos.empty()){

        for(int i = 0; i < mapa.fila; i++){

            for(int j = 0; j < mapa.columna; j++){

                if(vistos[i][j] && display[i][j] != INICIO && display[i][j] != META && display[i][j] != OBSTACULO) display[i][j] = VISTO;

            }

        }
    }

    for(Punto p : camino){

        if(!(p == mapa.inicio) && !(p == mapa.meta)) display[p.fila][p.columna] = CAMINO;

    }

    cout << "\n";
    cout << "====================================\n";
    cout << "          SEARCH ALGORITHMS\n";
    cout << "====================================\n\n";
    cout << "   ";

    for (int j = 0; j < mapa.columna; j++)
    {
        cout << j % 10 << " ";
    }

    cout << "\n";

    for (int i = 0; i < mapa.fila; i++)
    {
        cout << i % 10 << "  ";

        for (int j = 0; j < mapa.columna; j++)
        {
            cout << display[i][j] << " ";
        }

        cout << "\n";
    }

    cout << "\n";
    cout << "S = Inicio\n";
    cout << "G = Meta\n";
    cout << "# = Obstaculo\n";
    cout << "* = Vistos\n";
    cout << "o = Camino\n";

}

bool cargarMapa(Mapa& mapa, const string& archivo){

    ifstream file(archivo);

    if(!file) return false;

    int fila;
    int columna;

    file >> fila >> columna;

    file.ignore();

    mapa = crearMapa(fila, columna);

    for(int i = 0; i < fila; i++){

        string linea;

        getline(file,linea);

        if((int)linea.size()<columna) return false;

        for(int j = 0; j < columna; j++){

            char casilla = linea[j];

            if(casilla == INICIO){

                mapa.inicio = {i,j};

                mapa.grid[i][j] = INICIO;

            }else if(casilla == META){

                mapa.meta = {i,j};

                mapa.grid[i][j] = META;

            }else if(casilla == OBSTACULO){

                mapa.grid[i][j] = OBSTACULO;

            }else{

                mapa.grid[i][j] = VACIO;

            }
        }
    }

    file.close();

    return true;

}
