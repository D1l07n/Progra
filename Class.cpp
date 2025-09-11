#include <iostream>
#include <ctime>
using namespace std;

int students;
int grades;
int nMin = 1000, nMax = 8999;


void ingresoEstudiantes(int** matriz) {
    while (students < 10 || students > 30) {
        cout << "Cuantos estudiantes desea ingresar (minimo 10 y maximo 30): ";
        cin >> students;
    }

    while (grades < 5 || grades > 10) {
        cout << "Cuantas evaluaciones va a tener (minimo 5 y maximo 10): ";
        cin >> grades;
    }

    // +1 columna para el carné
    grades++;

   
    matriz = new int* [students];
    for (int i = 0; i < students; i++) {
        matriz[i] = new int[grades];
    }
}
void studentsInformation(int** matriz) {
    for (int f = 0; f < students; f++) {
        // carné aleatorio
        matriz[f][0] = nMin + rand() % (nMax - nMin + 1);

        // notas entre 0 y 100 múltiplos de 5
        for (int c = 1; c < grades; c++) {
            matriz[f][c] = (rand() % 21) * 5;
        }
    }

   
    cout << "\nMatriz de estudiantes (Carne + Notas):\n";
    for (int f = 0; f < students; f++) {
        for (int c = 0; c < grades; c++) {
            cout << matriz[f][c] << "\n";
        }
        cout << "\n";
    }
    cout << endl;
}


int* calcularPromedios(int** matriz) {
    int* promedios = new int[students];
    for (int f = 0; f < students; f++) {
        int suma = 0;
        for (int c = 1; c < grades; c++) {
            suma += matriz[f][c];
        }
        promedios[f] = suma / (grades - 1);
    }
    return promedios;
}


void top5(int* promedios, int** matriz) {
    cout << "Los 5 promedios mas altos son:\n";

    // copia de promedios para manipular sin dañar el original
    int* copia = new int[students];
    for (int i = 0; i < students; i++) {
        copia[i] = promedios[i];
    }

    for (int k = 0; k < 5; k++) {
        int maxProm = -1;
        int idx = -1;
        for (int i = 0; i < students; i++) {
            if (copia[i] > maxProm) {
                maxProm = copia[i];
                idx = i;
            }
        }
        if (idx != -1) {
            cout << "Estudiante con carne " << matriz[idx][0]
                << " tiene promedio " << promedios[idx] << endl;
            copia[idx] = -1; // marcar como ya usado
        }
    }

    delete[] copia;
}

int main() {
    srand(time(0));

    int** matriz = nullptr;

    ingresoEstudiantes(matriz);
    studentsInformation(matriz);

    int* promedios = calcularPromedios(matriz);

    cout << "Promedios por estudiante:\n";
    for (int i = 0; i < students; i++) {
        cout << "Estudiante " << i << " (Carne " << matriz[i][0]
            << "): " << promedios[i] << endl;
    }
    cout << endl;

    top5(promedios, matriz);

   
    delete[] promedios;
    for (int i = 0; i < students; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}