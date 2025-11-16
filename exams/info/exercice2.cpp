#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    
    int u0, u, u1, n = 60;
    int U[n];
    

    cout << "Saisir premier terme u0 : "; 
    cin >> u0;

    U[0] = u0;

    for (int i = 0; i <= n; i++) {
        U[i + 1] = (31 * U[i] + 7) % 29;
    }
    
    int somme = 0;
    for (int i = 0; i <= n; i++) {
        somme += U[i];
    }

    int occurence = 0;
    for (int i = 0; i <= n; i++) {
        if (U[i] == 1) {
            occurence++;
        }
    }

    int plusPetitEntierN = 1;
    while (plusPetitEntierN <= n && U[plusPetitEntierN] != u0){
        plusPetitEntierN++;
    }

    cout << "Somme des termes  : " << somme << endl;
    cout << "Occurence de la valeur 1 : " << occurence << endl;
    cout << "Plus petit entier n tel que Un = U0 : " << plusPetitEntierN << endl;

}