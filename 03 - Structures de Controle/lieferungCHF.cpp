//
// Created by leobe on 26/09/2024.
//

#include <iostream>

using namespace std;

int main() {
    cout << "Livraison en Suisse ? (O/N) ";
    char reponse1;
    cin >> reponse1;
    if (reponse1 == 'O') {
        cout << "Livraison Canton GR/TE ? (O/N) ";
        char reponse2;
        cin >> reponse2;
        if (reponse2 == 'O') {
            cout << "7.00 CHF merci" << endl;
        }else{
            cout << "5.00 CHF merci" << endl;
        }
    } else {
        cout << "Livraison au Lichtenstein ? (O/N) ";
        char reponse3; cin >> reponse3;
        if (reponse3 == 'O') {
            cout << "7.00 CHF merci" << endl;
        }else{
            cout << "10.00 CHF merci" << endl;
        }
    }

    // votre code vient ici
    return 0;
}