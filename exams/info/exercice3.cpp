#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

    int pointTotal = 0;

    for (int i = 0; i < 10; ++i) {
        
        int n1 = rand() % 6 + 1;
        int n2 = rand() % 6 + 1;
        int n3 = rand() % 6 + 1;

        cout << "Tirage numero " << i+1 << " n1=" << n1 << ", n2=" << n2 << ", n3=" << n3 << endl; 

        if (n1 == 4 && n2 == 2 && n3 == 1) {
            cout << " 4 2 1 Gagne" << endl << endl;
            pointTotal += 5;
        } else if ((n1 % 2 == 0) && (n2 % 2 == 0) && (n3 % 2 == 0)) {
            cout << " Pair Gagne" << endl << endl;
            pointTotal += 2;
        } else {
            cout << " Perdu" << endl << endl;
        }

        cout << "Point total = " << pointTotal << endl << endl; 

        if (pointTotal > 10) {
            break;
        }
    }
}
