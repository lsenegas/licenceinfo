#include <iostream>
#include <string>

using namespace std;

void inputValid (int &n, string &c1, string &c2) {
    do {
        cout << "Donnez n tel que 2 <= n <= 8: "; cin >> n;
    } while (n < 2 || n > 8);
    
    cout << "Donnez un premier caractère pour la figure: "; cin >> c1;
    cout << "Donnez en maintenant un second: "; cin >> c2;
}

void charSequence (string &c, int &n) {
    for (int i = 1; i <= n; i++) {
        cout << c;
    }
}

void printBlocLine (int &n, string &c1, string &c2) {
    for (int i = 0; i < n; i++){
        for (int i = 1; i <= n/2; i++) {
            charSequence(c1, n);
            charSequence(c2, n);
        } if (n%2 != 0) charSequence (c1,n);
        cout << endl;
    }
}

void checkerboardLayout (int &n, string &c1, string &c2) {
    for (int i = 1; i <= n; i++) {
        (i%2 == 0) ? printBlocLine (n,c2,c1):printBlocLine(n,c1,c2);
    }
    if (n%2 != 0) printBlocLine(n,c1,c2);    
}

int main() {
    int n;
    string c1, c2;
    inputValid(n, c1, c2);
    cout << endl;
    checkerboardLayout(n, c1, c2);
}
