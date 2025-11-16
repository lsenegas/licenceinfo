// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

int askForAge() {
    cout << "Enter your age: ";
    int retValue = -1;
    cin >> retValue;
    return retValue;
}

bool isAgeValid(int age) {
    return age >= 18;
}

bool isSexValid(char sex) {
    return (sex == 'M' || sex == 'F');
}

bool isYesOrNo(char answer) {
    return (answer == 'Y' || answer == 'N');
}

char askForSex() {
    cout << "Enter your sex (M/F): ";
    char retValue = 'Z';
    cin >> retValue;
    return retValue;
}

char askIsStudent() {
    cout << "Are you student (Y/N): ";
    char retValue = 'Z';
    cin >> retValue;
    return retValue;
}

bool isPassCulturAndSportAllowed(int age, char sex, bool isStudent) {
    bool retValue = false;
    
    if (isStudent && age < 26) {
        retValue = true;
    } else if (age > 65) {
        retValue = true;
    } else if (sex == 'F' && age < 40)  {
        retValue = true;
    }
    
    return retValue;
}

int main() {
    int age = askForAge();
    char sex = askForSex();
    char isStudent = askIsStudent();
    
    if (! isAgeValid(age) || ! isSexValid(sex) || ! isYesOrNo(isStudent)) {
        cout << "Data invalid !" << endl;
        return 0;
    } 
    
    if (isPassCulturAndSportAllowed(age, sex, isStudent == 'Y')) {
        cout << endl << "Congrats, you are eligible to the Pass Cultur And Sport" << endl;
    } else {
        cout << endl << "Sorry, you are not eligible to the Pass Cultur And Sport" << endl;
    }
    
    return 0;
}

