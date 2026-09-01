#include <iostream>
#include <vector>

using namespace std;

void merge (vector <int> & vec, int izquierda, int medio, int derecha) {
    int i, j, k;
    int n1 = medio - izquierda +1;
    int n2 = derecha -medio;

    vector <int> primerVector(n1), segundoVector(n2);

    for (i=0; i<n1; i++){
        primerVector[i] = vec[izquierda+i];
    }

    for (j=0; j<n2; j++){
        segundoVector[j] = vec[medio+1+j];
    }

    i = 0;
    j = 0;
    k = izquierda;

    while (i < n1 && j <n2)
    {
        if (primerVector[i] <= segundoVector[j]){
            vec[k] = primerVector[i];
            i++;

        }
        else {
            vec[k] = segundoVector[j];
            j++;
        }

        k++;
    }

    

    while (i < n1) {
        vec[k] = primerVector[i];
        i++;
        k++;
    }

    while (j < n2) {
        vec[k] = segundoVector[j];
        j++;
        k++;
    }
}

void mergeSort (vector <int> & vec, int izquierda, int derecha) {

   if (izquierda == derecha) {
        return;}

    else {
        int medio = ((derecha - izquierda)/2) + izquierda;

        mergeSort (vec, izquierda, medio);
        mergeSort(vec, medio+1, derecha);
        merge(vec, izquierda, medio, derecha);
    }
   }



int main () {

    vector<int> vector_1 = {4, -7, 1, 9, 12, -3, 3};
    vector<int> vector_2 = {9, 8, 7, 6, 1,-5};
    vector <int> vector_3 = {11};
    vector <int> vector_4 = {0, 1, 0, 1, 0, 1};

    cout << "Caso de prueba 1: " ;

    cout << "Vector original: ";
    
    for (int numero : vector_1){
        cout << numero << "   ";
    }
    
    mergeSort(vector_1, 0, vector_1.size()-1);

    cout << "Vector después de mergeSort: ";
    
    cout << endl;
    for (int numero : vector_1){
        cout << numero << "   ";
    }

    cout << endl;
    cout << endl;

    cout << "Caso de prueba 2: " ;

    cout << "Vector original: ";
    
    for (int numero : vector_2){
        cout << numero << "   ";
    }
    
    mergeSort(vector_2, 0, vector_2.size()-1);

    cout << "Vector después de mergeSort: ";
    
    cout << endl;
    for (int numero : vector_2){
        cout << numero << "   ";
    }

    cout << endl;
    cout << endl;


    cout << "Caso de prueba 3: " ;

    cout << "Vector original: ";
    
    for (int numero : vector_3){
        cout << numero << "   ";
    }
    
    mergeSort(vector_3, 0, vector_3.size()-1);

    cout << "Vector después de mergeSort: ";
    
    cout << endl;
    for (int numero : vector_3){
        cout << numero << "   ";
    }

    cout << endl;
    cout << endl;


    cout << "Caso de prueba 4: " ;

    cout << "Vector original: ";
    
    for (int numero : vector_4){
        cout << numero << "   ";
    }
    
    mergeSort(vector_4, 0, vector_4.size()-1);

    cout << "Vector después de mergeSort: ";
    
    cout << endl;
    for (int numero : vector_4){
        cout << numero << "   ";
    }

    cout << endl;
    cout << endl;

    return 0;


}


    

