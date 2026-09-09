#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Solicitar al usuario valores de las denominaciones de los billetes y el valor del producto y del billete

int get_values(int n, vector<int>& denominations) {

    cout << "ENTER THE DENOMINATIONS OF THE BILLS" << endl;

    for (int i = 0; i < n; i++) {

        cout << "Enter the value of denomination " << i + 1 << ": ";

        cin >> denominations[i];

        if (denominations[i] <= 0) {

            cout << "The denomination must be greater than zero. Try again" << endl;

            i--;

            continue;

        }

    }

/*for (int i = 0; i < denominations.size(); i++) {

        cout << denominations[i] << " ";

    }*/

   int P, Q;

   cout << "Enter the value of Product: " << endl;

   cin >> P ;

   cout << "Enter the value of Bill: " << endl;

   cin >> Q;

   int change = Q - P;

   sort(denominations.begin(), denominations.end(), greater<int>());

   return change;

}

//Sacar primera combinación posible en base a la denominación más grande que cabe en el cambio

vector<int> algoritmo_avaro(int change, const vector<int>& denominations) {

    vector<int> bills_used(denominations.size(), 0);

    for (size_t i = 0; i < denominations.size(); i++) {

        if (denominations[i] <= change) {

            int count = change / denominations[i];

            bills_used[i] = count;

            change -= count * denominations[i];

        }

    }

    return bills_used;

}

vector<int> dynamic_programming(int change, const vector<int>& denominations) {

    vector<int> values_array(change + 1, change + 1);

    vector<int> last_used_bill(change + 1, -1);

    values_array[0] = 0;

    for (int i = 1; i <= change; ++i) {

        for (size_t j = 0; j < denominations.size(); ++j) {

            int denomination = denominations[j];

            if (denomination <= i && values_array[i - denomination] != change + 1) {

                if (values_array[i - denomination] + 1 < values_array[i]) {

                    values_array[i] = values_array[i - denomination] + 1;

                    last_used_bill[i] = denomination;

                }

            }

        }

    }

    vector<int> bills_used(denominations.size(), 0);

    if (values_array[change] == change + 1) {

        return bills_used;

    }

    int remaining = change;

    while (remaining > 0) {

        int denomination = last_used_bill[remaining];

        for (size_t i = 0; i < denominations.size(); ++i) {

            if (denominations[i] == denomination) {

                bills_used[i]++;

                break;

            }

        }

        remaining -= denomination;

    }

    return bills_used;

}

int main() {

    vector<int> denominations(3);

    int change = get_values(3, denominations);

    if (change < 0) {

        cout << "The payment is not enough to cover the product." << endl;

        return 0;

    }

    vector<int> result_dp = dynamic_programming(change, denominations);

    vector<int> result_avaro = algoritmo_avaro(change, denominations);
    //Complejidad dinamica: O(n*m)
    cout << "Programacion dinamica:" << endl;
    for (size_t i = 0; i < denominations.size(); i++) {
        cout << "Denomination " << denominations[i]<< ": " << result_dp[i] << endl;
    }
    //Complejidad Avaro: O(nlogn)
    cout << "Algoritmo Avaro:" << endl;
    for (size_t i = 0; i < denominations.size(); i++) {
        cout << "Denomination " << denominations[i]<< ": " << result_avaro[i] << endl;
    }

    return 0;

}

/*
CASOS DE PRUEBA

Caso 1: Caso normal
Entrada:
N = 3
Denominaciones = [1, 5, 10]
P = 23
Q = 50
Cambio = 27

Caso 2: El algoritmo avaro no encuentra la solución óptima
Entrada:
N = 3
Denominaciones = [1, 3, 4]
P = 6
Q = 12
Cambio = 6

Caso 3: El cambio puede darse utilizando una sola moneda
Entrada:
N = 3
Denominaciones = [1, 5, 10]
P = 20
Q = 30
Cambio = 10

Caso 4: No existe una combinación exacta para el cambio
Entrada:
N = 3
Denominaciones = [4, 6, 10]
P = 7
Q = 10
Cambio = 3
*/