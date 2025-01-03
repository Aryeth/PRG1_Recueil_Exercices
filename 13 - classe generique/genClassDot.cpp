//
// Created by Aryeth on 02/01/2025.
//
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Coord;

template <typename V>
class Point {
public:

    Point() : name("origin"), coord(Coord<V>(0,0)){};

    Point(string name, V x = 0, V y = 0) : name(name), coord(Coord<V>(x,y)){};

    template <typename W>
    Point(string name, Coord<W> coord) : name(name), coord(coord){}

    void afficher() const {
        cout << "(" << this->coord.getX() << ", " << this->coord.getY() << ")";
    }

    void setNom(string name) {
        this->name = name;
    }

    string getNom() {
        return this->name;
    }

    Coord<V> getCoord() {
        return this->coord;
    }

    void deplacer(V x, V y) {
        this->coord.deplacer(x, y);
    }
    void setCoord(V x, V y) {
        this->coord.setCoord(x, y);
    }
    void setCoord(Coord<V> coord) {
        this->coord = coord;
    }

private:
    string name;
    Coord<V> coord;

};

template <typename T>
class Coord {
    friend class Point<T>;
public:

    Coord(T x, T y) : x(x), y(y){};

    template <typename U>
    Coord(U xVal, U yVal) : x(static_cast<T>(xVal)), y(static_cast<T>(yVal)) {}


    void afficher() const {
        cout << "(" << this->x << ", " << this->y << ")";
    }
    void setCoord(T x, T y) {
        this->x = x;
        this->y = y;
    }
    T getX() const {
        return x;
    }
    T getY() const {
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
    const Point<int> origin;

    cout << "p1       : ";
    Point<int> p1("p1"s);
    p1.afficher();
    cout << endl;

    cout << "p2       : ";
    Point<double> p2("p2"s, Coord(1.2, 3.4));
    p2.afficher();
    cout << endl;

    cout << "p3       : ";
    Point<double> p3("p3"s, 1.2, 3.4);
    p3.afficher();
    cout << endl;

    cout << "p3.1     : ";
    p3.setNom("p3.1"s);
    p3.afficher();
    cout << endl;

    cout << "p1(-1, 1): ";
    p1.setCoord(Coord(-1, 1));
    p1.afficher();
    cout << endl;

    cout << "p1->     : ";
    p1.deplacer(-1, 1);
    p1.afficher();
    cout << endl;

    cout << "p1(x)    : ";
    cout << p1.getNom() << " " << p1.getCoord().getX();
}
