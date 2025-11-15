#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

// Función para leer el archivo de texto
int leerArchivo(string nombreArchivo, int numeros[]) {
    ifstream archivo(nombreArchivo);
    int i = 0;

    if (archivo.is_open()) {
        while (archivo >> numeros[i] && i < 100) {
            i++;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    return i; // Devuelve cuántos números se leyeron
}

// Función para clasificar números pares e impares
void clasificarNumeros(int numeros[], int tam, int pares[], int &tamP, int impares[], int &tamI) {
    tamP = tamI = 0;

    for (int k = 0; k < tam; k++) {
        if (numeros[k] % 2 == 0) {
            pares[tamP++] = numeros[k];
        } else {
            impares[tamI++] = numeros[k];
        }
    }
}

// Ordenamiento
void ordenarArchivo(int numeros[], int tam) {
    sort(numeros, numeros + tam);
}

// Mostrar arreglo
void mostrarArchivo(const int numeros[], int tam) {
    for (int i = 0; i < tam; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;
}

// Guardar en archivo
void guardarEnArchivo(string nombre, const int datos[], int tam) {
    ofstream archivo(nombre);
    for (int i = 0; i < tam; i++) {
        archivo << datos[i] << " ";
    }
}

int main() {
    const int TAM = 100;
    int numeros[TAM], pares[TAM], impares[TAM];
    int tamNum, tamP, tamI;

    // Crear archivo de texto
    ofstream archivo("datos.txt");
    archivo << "1 3 5 7 9 2 4 6 8 10";
    archivo.close();

    // Leer archivo
    tamNum = leerArchivo("datos.txt", numeros);

    cout << "Contenido original del archivo:\n";
    mostrarArchivo(numeros, tamNum);

    // Clasificar
    clasificarNumeros(numeros, tamNum, pares, tamP, impares, tamI);

    cout << "\nPares sin ordenar:\n";
    mostrarArchivo(pares, tamP);

    cout << "Impares sin ordenar:\n";
    mostrarArchivo(impares, tamI);

    // Ordenar
    ordenarArchivo(pares, tamP);
    ordenarArchivo(impares, tamI);

    cout << "\nPares ordenados:\n";
    mostrarArchivo(pares, tamP);

    cout << "Impares ordenados:\n";
    mostrarArchivo(impares, tamI);

    // Guardar resultados
    guardarEnArchivo("pares.txt", pares, tamP);
    guardarEnArchivo("impares.txt", impares, tamI);

    // Menú
    int opcion;
    do {
        cout << "\n--- MENÚ ---\n";
        cout << "1. Clasificar números\n";
        cout << "2. Ordenar archivos\n";
        cout << "3. Ver resultados\n";
        cout << "4. Salir\n";
        cout << "Ingrese opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                clasificarNumeros(numeros, tamNum, pares, tamP, impares, tamI);
                cout << "Clasificación realizada.\n";
                break;

            case 2:
                ordenarArchivo(pares, tamP);
                ordenarArchivo(impares, tamI);
                cout << "Archivos ordenados.\n";
                break;

            case 3:
                cout << "\nPares:\n";
                mostrarArchivo(pares, tamP);
                cout << "Impares:\n";
                mostrarArchivo(impares, tamI);
                break;

            case 4:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opción inválida.\n";
        }

    } while (opcion != 4);

    return 0;
}
