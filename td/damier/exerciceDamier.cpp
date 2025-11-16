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

void oneLine (int &n, string &c1, string &c2) {
    if (n % 2 == 0) {
        for (int i = 1; i <= n/2; i++) {
            charSequence(c1, n);
            charSequence(c2, n);
        }
        cout << endl;
    } else {
        for (int i = 1;i <= n/2; i++) {
            charSequence(c1, n);
            charSequence(c2, n);
        } charSequence(c1, n);
        cout << endl;
    } 
}

void checkerboardLayout (int &n, string &c1, string &c2) {
    if (n % 2 == 0) {
        for (int i = 1; i <= n/2; i++) {
            oneLine(n, c1, c2);
            oneLine(n, c1, c2);
        }
        for (int i = 1; i <= n/2; i++) {
            oneLine(n, c2 ,c1);
            oneLine(n, c2 ,c1);
        }
    } else {
        for (int i = 1; i <= n/2; i++) {
            oneLine(n, c1, c2);
            oneLine(n, c1, c2);
        }oneLine(n, c1, c2);
        for (int i = 1; i <= n/2; i++) {
            oneLine(n, c2, c1);
            oneLine(n, c2, c1);
        }oneLine(n, c2, c1);
    }
}

int main() {
    int n;
    string c1, c2;
    inputValid(n, c1, c2);
    cout << endl;
    checkerboardLayout(n, c1, c2);
}
