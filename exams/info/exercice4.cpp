#include <iostream>

using namespace std;

int main() {

    for (int a = 1; a < 10; a++) {
        for (int b = 1; b < 10; b++) {
            if ((a + b) % 3 == 0 && ((a % 7 == 0) || (b % 7 == 0))) {
                cout << "("<< a << ", " << b << ")" << endl;
            }
        }
    }
}
