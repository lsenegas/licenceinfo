// Online C++ compiler to run C++ program online
#include <iostream>
#include <array>
#include <cmath>

using namespace std;
const int MAX_MESURES = 120;

using tabmesures = array<double, MAX_MESURES>;

bool isNbValid(int value) {
    return ((value >= 1) && (value <= MAX_MESURES));
}

void saisirMesures(tabmesures& mes, int& nb) {
    cout << "Nombre de mesures à saisir ? "; 
    cin >> nb;
    while (! isNbValid(nb)) {
        cout << "Erreur saisie invalide, resaisir : ";
        cin >> nb;
    }
    
    cout << "Saisie des " << nb << " mesures." << endl;
    for (int i = 0; i < nb; i++) {
        cout << "Saisir la mesure [" << i << "] : " << endl;
        cin >> mes[i];
    }
}

void test() {
    cout << "isNbValid(5): " << boolalpha << isNbValid(5) << endl;
    cout << "isNbValid(-1): " << boolalpha << isNbValid(-1) << endl;
    cout << "isNbValid(0): " << boolalpha << isNbValid(0) << endl;
    cout << "isNbValid(MAX_MESURES): " << boolalpha << isNbValid(MAX_MESURES) << endl;
    cout << "isNbValid(MAX_MESURES + 1): " << boolalpha << isNbValid(MAX_MESURES + 1) << endl;
    
}

void afficherMesures(tabmesures& mes, int& nb) {
    for (int i = 0; i < nb; i++) {
        cout << mes[i];
        if (i < nb - 1) cout << ", ";
    }
}

double moyenne(tabmesures& mes, int& nb) {
    double somme = 0;
    for (int i = 0; i < nb; i++) {
        somme += mes[i];
    }
    return somme / nb;
}

double ecartType(tabmesures& mes, int& nb) {
    double mu = moyenne(mes, nb);
    double somme = 0;
    for (int i = 0; i < nb; i++) {
        somme += pow(mes[i] - mu, 2);
    }
    return sqrt(somme/nb);
}

void moyenneEtEcartType(tabmesures& mes, int& nb){
    
}

int main() {
    //test();
    tabmesures mesures;
    int nb;
    saisirMesures(mesures, nb);
    afficherMesures(mesures, nb);
    cout << endl << "moyenne = " << moyenne(mesures, nb) << endl;
    cout << endl << "Ecart Type = " << ecartType(mesures, nb) << endl;
    
    
    return 0;
}