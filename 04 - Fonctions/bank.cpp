//
// Created by leobe on 02/10/2024.
//

#include <iostream>

using namespace std;

// Nothing could go wrong, right ? :3
int* soldePtr;

string retrait(int solde, int montant) {

    if(solde < montant) {
        montant = solde;
        *soldePtr -= montant;
    }else{
        *soldePtr -= montant;
    }

    return to_string(montant);
}

int main() {
    int solde = 500;
    soldePtr = &solde;
    cout << "solde : " << solde << endl;
    cout << " retrait de : " << retrait(solde, 300) << endl;
    cout << "solde : " << solde << endl;
    cout << " retrait de : " << retrait(solde, 300) << endl;
    cout << "solde : " << solde << endl;
    return 0;
}