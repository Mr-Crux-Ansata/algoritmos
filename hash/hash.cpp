#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


void hashed(string filename, int n) {
    //Abrir y leer archivo
    ifstream file(filename, ios::binary);
    if (!file.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }
    char c;
    vector<vector<int>> tabla;
    tabla.push_back(vector<int>());
    int columna = 0;
    int fila = 0;
    
    //Meter valores en tabla. Complejidad computacional O(m), pues recorer todos los caracteres
    while (file.get(c)){
        int asc_number = (int)c;
        if (columna == n){
            columna = 0;
            fila++;
            tabla.push_back(vector<int>());
        }
        tabla[fila].push_back(asc_number);
        columna++;
    }
    //Quitar fila si está vacía, ocurre solo cuando el tamaño de la última fila es de 4 elementos
    if (tabla[fila].empty()){
        fila--;
    }
    int size_final_row=tabla[fila].size();
    if (!(size_final_row==(n))){
        for (int i=size_final_row;i<n;i++){
            tabla[fila].push_back(n);
        }
    }
    vector <int> mods;

    //Cálculos por elemento
    //Complejidad tempora: O(m), pues recorre todos los elementos

    for (int i = 0; i < n; i++){
        int suma = 0;
        for (int j = 0; j<=fila;j++){
            suma+=tabla[j][i];
        }
        mods.push_back(suma%256);
    }

    string texto_hash;
    string valores_hex = "0123456789ABCDEF";

//Convertir valores a hexadecimal. Complejidad temporal O(n)
    for ( int i=0;i<mods.size();i++){
        int valor_mods = mods[i];
        int primer = valor_mods / 16;
        int segundo = valor_mods%16;
        char primer_dig = valores_hex[primer];
        char segundo_dig= valores_hex[segundo];
        texto_hash += primer_dig; 
        texto_hash += segundo_dig;

    }
    cout << "HASH STRING OBTENIDO CON LAS ENTRADAS "<<"n = " << n << " Y EL ARCHIVO " << filename << endl << endl;
    cout << texto_hash << endl << endl;
};

//Complejidad temporal resultante: O(m+n)
int validar_n(){
    int n=0;
    while (true){
        cout << "Ingrese el valor de n: " << endl;
        cin >> n;
        if (n>=16 && n<=64 && n%4==0){
            return n;
        }
        else{
            cout << "El valor de n debe estar entre 16 y 64 y ser múltiplo de 4" << endl;
            continue;
        } 
    }
} ;

int main(){
    // Caso 1: texto con múltiples caracteres y saltos de línea
    // n = 16
    int n = validar_n();
    string filename = "texto_plano0.txt";
    hashed(filename, n);

    // Caso 2: caracteres repetidos
    // n = 16
    n = validar_n();
    filename = "texto_plano1.txt";
    hashed(filename, n);

    // Caso 3: varias palabras, líneas vacías y saltos de línea
    // n = 48
    n = validar_n();
    filename = "texto_plano2.txt";
    hashed(filename, n);

    // Caso 4: números, símbolos y letras
    // n = 24
    n = validar_n();
    filename = "texto_plano3.txt";
    hashed(filename, n);

    // Caso Adicional: N no cumple los requerimientos
    n = validar_n();
 
    return 0;


};

/*Reflexion
Durante este ejercicio me fue posible comprender de manera plena y 
detallada el funcionamiento del algoritmo hash, así como de las condiciones
bajo las cuales trabaja. Para realizar el ejercicio, lo dividí en varias etapas. 
En la primera, simplemente se fue colocando caracter por caracter en una tabla, 
posteriormente, el cálculo de valores y, por último, generar la cadena hexadecimal. 
Cabe mencionar que nos será de gran utilidad para la implementación del hashing de
 contraseñas en el proyecto central de la materia de seguridad./**/

    

