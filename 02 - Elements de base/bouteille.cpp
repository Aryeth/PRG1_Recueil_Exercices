//
// Created by leobe on 24/09/2024.
// Calculates the volume of a bottle with user input
//
#include <iostream>

using namespace std;

int main() {
    double rayonCyl1;
    double rayonCyl2;
    double hauteurCyl1;
    double hauteurCyl2;
    double hauteurCone;
    double volumeTotal;

    cout << "Entrez le rayon du cylindre 1 [cm] :";
    cin >> rayonCyl1;
    cout << endl << "Entrez le rayon du cylindre 2 [cm] :";
    cin >> rayonCyl2;
    cout << endl << "Entrez la hauteur du cylindre 1 [cm] :";
    cin >> hauteurCyl1;
    cout << endl << "Entrez la hauteur du cylindre 2 [cm] :";
    cin >> hauteurCyl2;
    cout << endl << "Entrez la hauteur du cone [cm] :";
    cin >> hauteurCone;
    cout << endl << endl;

    volumeTotal = M_PI * rayonCyl1*rayonCyl1 * hauteurCyl1 + rayon;

    return 0;
}