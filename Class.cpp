#include <iostream>
#include <ctime>
using namespace std;

int students;
int grades;
int nMin = 1000, nMax = 8999;


int** ingresoEstudiantes() {
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

   
   int** matriz = new int* [students];
    for (int i = 0; i < students; i++) {
        matriz[i] = new int[grades];
    }
    return matriz;
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
            cout << matriz[f][c]<<"\t";
        }
        cout << "\n";
    }
    cout << endl;
}


int* Averages(int** matriz) {
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


void mAverages(int* promedios, int** matriz) {
    cout << "Los 5 promedios mas altos son:\n";
    
    for (int i = 0; i < students - 1; i++) {
        for (int j = 0; j < students - i - 1; j++) {
            if (promedios[j] < promedios[j + 1]) {
                int temp = promedios[j];
                promedios[j] = promedios[j + 1];
                promedios[j + 1] = temp;

                int tempC = matriz[j][0];
                matriz[j][0] = matriz[j + 1][0];
                matriz[j + 1][0] = tempC;
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        cout << "Estudiante con carne " << matriz[i][0];
        cout << " Promedio " << promedios[i] << "\n";



    }
}

int main() {
    srand(time(0));

    int** matriz = ingresoEstudiantes();

  
    studentsInformation(matriz);

    int* promedios = Averages(matriz);

    cout << "Promedios por estudiante:\n";
    for (int i = 0; i < students; i++) {
        cout << "Estudiante " << i << " Carne " << matriz[i][0] << ": " << promedios[i] << endl;
    }
    cout << endl;

    mAverages(promedios, matriz);

   
    delete[] promedios;
    for (int i = 0; i < students; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}