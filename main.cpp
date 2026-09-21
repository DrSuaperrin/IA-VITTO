#include <iostream>

#include "Inicializador.h"
#include "Mapa.h"
#include "Utilidades.h"
#include "DFS.h"

using namespace std;

int main()
{
    // ==========================================
    // CREAR MAPA
    // ==========================================

    int filas;
    int columnas;

    cout << "====================================\n";
    cout << "       PROYECTO 3 - DFS\n";
    cout << "====================================\n\n";

    cout << "Ingresa el numero de filas: ";
    cin >> filas;

    cout << "Ingresa el numero de columnas: ";
    cin >> columnas;

    Mapa mapa = crearMapa(
        filas,
        columnas
    );

    // ==========================================
    // ESTABLECER INICIO
    // ==========================================

    int fila;
    int columna;

    cout << "\n--- Posicion inicial ---\n";

    cout << "Fila: ";
    cin >> fila;

    cout << "Columna: ";
    cin >> columna;

    setInicio(mapa,{fila, columna});

    // ==========================================
    // ESTABLECER META
    // ==========================================

    cout << "\n--- Posicion de la meta ---\n";

    cout << "Fila: ";
    cin >> fila;

    cout << "Columna: ";
    cin >> columna;

    setMeta(mapa,{fila, columna});

    // ==========================================
    // AGREGAR OBSTACULOS
    // ==========================================

    char respuesta;

    do
    {
        imprimir_mapa(mapa);

        cout << "\nQuieres agregar un obstaculo? (s/n): ";
        cin >> respuesta;

        if (
            respuesta == 's' ||
            respuesta == 'S'
        )
        {
            cout << "Fila: ";
            cin >> fila;

            cout << "Columna: ";
            cin >> columna;

            setObstaculos(mapa,{fila, columna});
        }

    } while (
        respuesta == 's' ||
        respuesta == 'S'
    );

    // ==========================================
    // MOSTRAR MAPA INICIAL
    // ==========================================

    cout << "\n\n====================================\n";
    cout << "          MAPA INICIAL\n";
    cout << "====================================\n";

    imprimir_mapa(mapa);

    // ==========================================
    // EJECUTAR DFS
    // ==========================================

    cout << "\n\n====================================\n";
    cout << "          EJECUTANDO DFS\n";
    cout << "====================================\n";

    Resultado_Busqueda resultado = DFS(mapa);

    // ==========================================
    // MOSTRAR RESULTADO
    // ==========================================

    mostrarResultado(
        mapa,
        resultado
    );

    return 0;
}
