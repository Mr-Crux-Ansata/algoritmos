#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


void open_txt(string filename, int n) {
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
    while (file.get(c)){
        int asc_number = (int)c;
        if (columna == n){
            columna = 0;
            fila++;
            continue;
        }
        else {
            tabla[fila].push_back(asc_number);
            columna++;
            continue;
        }
    }
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

    for (int i = 0; i<columna;i++){
        int suma = 0;
        for (int j = 0; j<fila;j++){
            suma+=tabla[i][j];
        mods.push_back(suma%256);
        }
    }

    string texto_hash;

    for ( int i=0;i<mods.size();i++){
        int valor_mods = mods[i];
        int primer_dig = valor_mods / 16;
        int segundo_dig = valor_mods%16;
        string primer_dig = to_string(primer_dig);
        string segundo_dig= to_string(segundo_dig);
        texto_hash += primer_dig + segundo_dig;

    }

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
}      
    

