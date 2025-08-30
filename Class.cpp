

#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    
    int students = 0;
    int grades = 0;
    int sum = 0;
    int min = 1000, max = 8999;
    int promedio=0;
   
    
    while (students < 10 || students>30) {
        cout << "Cuantos estudiantes desea ingresar (minimo 10 y maximo 30): ";
        cin >> students;

    }
    int** matriz = new int* [students];

    while (grades < 5 || grades>10) {
        cout << "Cuantas evaluaciones va a tener (minimo 5 y maximo 10): ";
        cin >> grades;

    }
    grades++;

    for (int i = 0; i < students; i++) {
        matriz[i] = new int[grades];
    }
    
    cout << endl;
    
    for (int f = 0; f < students; f++) {
        for (int c = 0; c < grades; c++) {
            matriz[f][0] = min + rand() % (max - min);
            matriz[f][c] = (rand() % 21) * 5;  
            
        }
    }
    

    for (int f = 0; f < students; f++) {
       
        for (int c = 0; c < grades; c++) {
            cout << matriz[f][c] << "\t";
        }
        cout << "\n";
    }

    cout << endl;
    int* Notes;
     Notes = new int[students];
   
       
    
    for (int i = 1; i < grades; i++) {
        sum += matriz[student][i];
        promedio = sum / (grades-1);
        

    }
    for (int i = 0; i < students; i++) {
        cout << Notes[i];

    }


    
    return 0;

}

