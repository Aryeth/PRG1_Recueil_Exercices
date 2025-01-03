//
// Created by Aryeth on 02/01/2025.
//
#include <iostream>
#include <string>
#include <vector>

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
    int getQuadrant() {
        V x = this->coord.getX();
        V y = this->coord.getY();
        if(x==0 || y ==0) return 0;
        if(x<0) {
            if(y<0) return 3;
            return 2;
        }
        if(y<0) return 4;
        return 1;
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
    vector<Point<int>> dessin {{"p1",  1,  2},
                           {"p2",  4,  2},
                           {"p3",  9,  8},
                           {"p4", -1,  5},
                           {"p5",  3, -1},
                           {"p6",  7,  0}};

    for(Point p : dessin) {
        cout << "Nom : " << p.getNom() << endl << "Quadrant : "<< p.getQuadrant() << endl;
    }
}
