#include <iostream>
#include <iomanip>

using namespace std;

const int NB_LIGNES_MAX = 100;
const int NB_COLONNES_MAX = 100;
typedef int tabInt2D[NB_LIGNES_MAX][NB_COLONNES_MAX];

struct matrice {
    tabInt2D coef;
    int nbLignes;
    int nbColonnes;
};

void affiche(matrice &m) {
    cout << "Matrice (" << m.nbLignes << "x" << m.nbColonnes << ")" << endl;
    for (int i = 0; i < m.nbLignes; i++) {
        cout << "{";
        for (int j = 0; j < m.nbColonnes; j++) {
            cout << std::setw(2) << m.coef[i][j];
            if (j < m.nbColonnes - 1) cout << ", ";
        }
        cout << "}" << endl;
    }
}

int somme(matrice &m) {
    int resultat = 0;
    for (int i = 0; i < m.nbLignes; i++) {
        for (int j = 0; j < m.nbColonnes; j++) {
            resultat += m.coef[i][j];
        }
    }
    return resultat;
}

void transpose(matrice &m) {
    if (m.nbLignes != m.nbColonnes) return;

    for (int i = 0; i < m.nbLignes; i++) {
        for (int j = 0; j < i; j++) {
            int tmp = m.coef[i][j];
            m.coef[i][j] = m.coef[j][i];
            m.coef[j][i] = tmp;
        }
    }
}

bool recherche(matrice &m, int x) {
    bool trouve = false;
    for (int i = 0; i < m.nbLignes; i++) {
        for (int j = 0; j < m.nbColonnes; j++) {
            if (m.coef[i][j] == x) {
                trouve = true;
                break;
            }
        }
    }
    return trouve;
}

void insereColonne(matrice &m, int c) {
    if (c < 0 || c > m.nbColonnes) return;
    for (int i = 0; i < m.nbLignes; i++) {
        for (int j = m.nbColonnes - 1; j >= c; j--) {
            m.coef[i][j + 1] = m.coef[i][j];
        }
        m.coef[i][c] = 0;
    }
    m.nbColonnes++;
}

void premiereExtremite(matrice &m, int l, int c, int &l1, int &c1) {
    if (l == 0 || c == 0) {
        l1 = l;
        c1 = c;
        return;
    }
    premiereExtremite(m, l - 1, c - 1, l1, c1);
}

void deuxiemeExtremite(matrice &m, int l, int c, int &l2, int &c2) {
    if (l == m.nbLignes - 1 || c == m.nbColonnes - 1) {
        l2 = l;
        c2 = c;
        return;
    }
    deuxiemeExtremite(m, l + 1, c + 1, l2, c2); 
}

void extremiteDiagonale(matrice &m, int l, int c, int &l1, int &c1, int &l2, int &c2) {
    cout << "Extremite diagonale pour (" << l << ", " << c << ") coef = " << m.coef[l][c] << endl;

    premiereExtremite(m, l, c, l1, c1);
    deuxiemeExtremite(m, l, c, l2, c2);

    cout << "l1 = " << l1 << " c1 = " << c1 << " coef = " << m.coef[l1][c1] << endl;
    cout << "l2 = " << l2 << " c2 = " << c2 << " coef = " << m.coef[l2][c2] << endl;
}

bool estAuDessusOuSurDiagonale(int i, int j, int l, int c) {
    return (i - j <= l - c);
}

void decaleDiagonale(matrice &m, int l, int c) {
    insereColonne(m, m.nbColonnes);
    for (int i = 0; i < m.nbLignes; i++) {
        for (int j = m.nbColonnes - 2; j >= 0; j--) {
            if (estAuDessusOuSurDiagonale(i, j, l, c)) {
                m.coef[i][j + 1] = m.coef[i][j];
                m.coef[i][j] = 0;
            }
        }
    }
}

void retourne(char* message) {
    if (*message == '\0') {
        return;
    }
    retourne(message + 1);
    cout << *message;
}

int main() {
    matrice m = {{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    }, 3, 3};

    affiche(m);
    cout << "Somme matrice" << endl;
    cout << "Resultat : " << somme(m) << endl;

    cout << "Transpose matrice" << endl;
    transpose(m);
    affiche(m);

    int x = 9;
    cout << "Recherche " << x << " : " << std::boolalpha << recherche(m, x) << endl;

    int c = 3;
    cout << "Insere colonne " << c << endl;
    insereColonne(m, c);
    affiche(m);

    matrice m1 = {{
        { 1,  2,  3,  4,  5,  6,  7},
        { 8,  9, 10, 11, 12, 13, 14},
        {15, 16, 17, 18, 19, 20, 21},
        {22, 23, 24, 25, 26, 27, 28}
    }, 4, 7};

    affiche(m1);

    int l1 = -1;
    int c1 = -1;
    int l2 = -1;
    int c2 = -1;    
    extremiteDiagonale(m1, 1, 2, l1, c1, l2, c2); 
    decaleDiagonale(m1, 1, 2);
    affiche(m1);

    matrice m2 = {{
        { 1,  2,  3},
        { 4,  5,  6},
        { 7,  8,  9},
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18},
        {19, 20, 21},
        {22, 23, 24}
    }, 8, 3};
    affiche(m2);
    //extremiteDiagonale(m2, 3, 1, l1, c1, l2, c2); 
    decaleDiagonale(m2, 3, 1); 
    affiche(m2);

    char message[] = {'B', 'o', 'n', 'j', 'o', 'u', 'r', '!', '\0'};
    retourne(message);
}
