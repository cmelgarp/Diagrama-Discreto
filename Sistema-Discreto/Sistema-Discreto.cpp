// Sistema-Discreto.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <random>

    using namespace std;

    void Retraso()
    {
        cout << "Ha habido un retraso en el ascensor. El sistema es inestable." << endl;
    }
    int main() {


        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(1, 29);
        int cantidadDeTrabajadores = dist(gen);
        int cantidadPermitida = 20;

        cout << "--- SIMULACION SISTEMA DISCRETO DE ELEVADOR ---" << endl;
        cout << "Trabajadores hoy: " << cantidadDeTrabajadores << endl;

        if (cantidadDeTrabajadores > cantidadPermitida)
        {
            Retraso();
        }
        else
        {
            for (int hora = 7; hora <= 17; hora++) {

                cout << "Hora: " << hora << ":00 -> ";

                if (hora < 8) {
                    cout << "[Estado: INACTIVA]" << endl;
                }
                else if (hora == 8) {
                    cantidadDeTrabajadores = dist(gen); 
                    while (cantidadDeTrabajadores > cantidadPermitida)
                    {
                        if (hora == 8) cout << "(Inicio de jornada laboral) ";
                        cout << "[Estado: ACTIVA - Jornada matutina laboral]" << endl;

                    }
                     
                }
                else if (hora < 13) {
                    if (hora < 13) cout << "(Entre de jornada laboral) ";
                    cout << "[Estado: INACTIVO - Jornada matutina laboral]" << endl;
                }
                else if (hora == 13) {
                    cantidadDeTrabajadores = dist(gen);
                    while (cantidadDeTrabajadores > cantidadPermitida)
                    {
                        cout << "(Inicio Hora de almuerzo) ";
                        cout << "[Estado: ACTIVA - Horario de almuerzo]" << endl;
                    }
                }
                else if (hora > 13 && hora < 14) {
                    if (hora == 13) cout << "(Hora entre almuerzo) ";
                    cout << "[Estado: INACTIVA - Horario de almuerzo]" << endl;
                }
                else if (hora >= 14 && hora < 16) {
                    cantidadDeTrabajadores = dist(gen);
                    while (cantidadDeTrabajadores > cantidadPermitida)
                    {
                        if (hora == 14) cout << "(Finalización de almuerzo) ";
                        cout << "[Estado: ACTIVA - Retorno de horario laboral]" << endl;
                    }
                }
                else if (hora >= 16) {
                    if (hora == 16) cout << "(Finalización de jornada laboral) ";
                    cout << "[Estado: INACTIVA - Horario laboral terminado]" << endl;
                }
            }

        }

        return 0;
    }


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
