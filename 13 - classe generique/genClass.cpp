//
// Created by Aryeth on 02/01/2025.
//
#include <iostream>

using namespace std;

template <typename T>
class Coord {
    public:

    Coord() : x(0), y(0){};

    template <typename U>
    Coord(U xVal, U yVal) : x(static_cast<T>(xVal)), y(static_cast<T>(yVal)) {}


    void afficher() const {
        cout << "(" << this->x << ", " << this->y << ")";
    }
    void setCoord(T x, T y) {
        this->x = x;
        this->y = y;
    }
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }

    void deplacer(T x, T y) {
        this->x += x;
        this->y += y;
    }
    private:
    T x;
    T y;

};

int main() {
    cout << "origine  : ";
    const Coord<int> origin;
    origin.afficher();
    cout << endl;

    cout << "p1       : ";
    Coord<int> p1;
    p1.setCoord(1, 2);
    p1.afficher();
    cout << endl;

    cout << "p2       : ";
    Coord<double> p2(3, 4);
    p2.afficher();
    cout << endl;

    cout << "p2->     : ";
    p2.deplacer(1, 1);   // conversion int => double
    cout << "(" << p2.getX() << ", " << p2.getY() << ")";
    cout << endl;
}
