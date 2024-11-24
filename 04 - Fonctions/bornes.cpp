//
// Created by leobe on 02/10/2024.
//

#include <iostream>

using namespace std;

string born2Display(char min, char max);

int main() {
    char min;
    char max;
    cout << "Entrer borne inferieure :";
    cin >> min;
    cout << endl<< "Entrer borne superieure :";
    cin >> max;
    cout << endl;
    cout << "Votre borne : " << born2Display(min, max) << endl;
    return 0;
}

string born2Display(char min, char max) {
    string borne;
    for (char i = min; i <= max; i++) {
        borne += i;
    }
    return borne;
}