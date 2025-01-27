//
// Created by Aryeth on 27/01/2025.
//

#include <array>
#include <iostream>
#include <vector>
using namespace std;

using Vec3 = array<double, 3>;
using Matrice3x3 = array<array<double, 3>,3>;



string to_string(Vec3 const& v) {
    string vecStringed ="[";
    for(size_t i = 0; i<v.size();i++) {
        vecStringed += to_string((int)v[i]);
        if(i<v.size()-1)
        vecStringed += ", ";
    }
    return vecStringed +="]";
}

string to_string(Matrice3x3 const& matrix) {
    string matStringed = "[";
    for(size_t i = 0; i<matrix.size();i++) {
        matStringed += to_string(matrix[i]);
        if(i<matrix.size()-1)
            matStringed+="\n";
    }
    return matStringed+="]";
}

Vec3 produit(Matrice3x3 const& m, Vec3 const& vec) {
    Vec3 result{};
    for(size_t i = 0; i < m.size(); ++i) {
        for(size_t j = 0; j < m.size(); ++j) {
            result[i] += m[i][j] * vec[j];
        }
    }
    return result;
}

int main() {

    Matrice3x3 m = {1, 1, 0, 0, 2, 0, 0, 0, 1};
    Vec3 v = {1, 2, 3};
    Vec3 w = produit(m,v);

    cout << to_string(m) << " * "
         << to_string(v) << " = "
         << to_string(w) << endl;
}