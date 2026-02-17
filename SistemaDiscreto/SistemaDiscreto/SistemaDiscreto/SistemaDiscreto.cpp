#include <iostream>0
#include <string>

using namespace std;

int main() {
    cout << "--- SIMULACION SISTEMA DISCRETO DE ELEVADOR ---" << endl;

    for (int hora = 7; hora <= 17; hora++) {

        cout << "Hora: " << hora << ":00 -> ";

        if (hora < 8) {
            cout << "[Estado: INACTIVA]" << endl;
        }
        else if (hora == 8) {
            if (hora == 8) cout << "(Inicio de jornada laboral) ";
            cout << "[Estado: ACTIVA - Jornada matutina laboral]" << endl;
        }
        else if (hora <  13) {
            if (hora < 13 ) cout << "(Entre de jornada laboral) ";
            cout << "[Estado: INACTIVO - Jornada matutina laboral]" << endl;
        }
        else if (hora == 13) {
            cout << "(Inicio Hora de almuerzo) ";
            cout << "[Estado: ACTIVA - Horario de almuerzo]" << endl;
        }
        else if (hora > 13 && hora < 14) {
            if (hora == 13) cout << "(Hora entre almuerzo) ";
            cout << "[Estado: INACTIVA - Horario de almuerzo]" << endl;
        }
        else if (hora >= 14 && hora < 16) {
            if (hora == 14) cout << "(Finalización de almuerzo) ";
            cout << "[Estado: ACTIVA - Retorno de horario laboral]" << endl;
        }
        else if (hora >= 16) {
            if (hora == 16) cout << "(Finalización de jornada laboral) ";
            cout << "[Estado: INACTIVA - Horario laboral terminado]" << endl;
        }
    }
    return 0;
}
