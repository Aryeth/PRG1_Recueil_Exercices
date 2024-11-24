//
// Created by leobe on 24/09/2024.
// Converts meter to miles feet and inches
//
#include <iostream>

using namespace std;

int main() {
    double metre;
    double pieds;
    double pouces;
    double miles;

    cout << "Entrez le nombre de metres a convertir (entier > 0) :";
    cin >> metre;

    pieds = metre * 3.28084;
    pouces = metre * 39.3701;
    miles = metre * 0.000621371;

    cout << metre << "[m]" << endl;
    cout << "= " << miles << " [mile]" << endl;
    cout << "= " << pieds << " [ft]" << endl;
    cout << "= " << pouces << " [inch]" << endl;

    return 0;
}