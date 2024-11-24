//
// Created by leobe on 02/10/2024.
//

#include <iostream>

using namespace std;

double pyramideCalculate(double l1, double l2, double h) {
    double volume = 1.0/3.0*(l1*l2*h);
    int partieEntiere = volume;
    int virgule = (volume*10 - partieEntiere*10);
    string total = to_string(partieEntiere)+to_string(virgule);
    return stod(total)/10;
}

int main() {
    double longueur, largeur, hauteur;

    cout << "Entrez la longeur de la base: ";
    cin >> longueur;
    cout << "Entrez la largeur de la base : ";
    cin >> largeur;
    cout << "Entrez la hauteur : ";
    cin >> hauteur;
    double total = pyramideCalculate(longueur, largeur, hauteur);
    cout << " Le volume de la pyramide est de : " << total << " [m^3] ";
    cout << endl;
    return 0;
}