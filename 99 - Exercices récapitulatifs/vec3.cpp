//
// Created by Aryeth on 29/01/2025.
//
#include <iostream>
#include <array>
#include <vector>
#include <cassert>
using namespace std;

class Vec3 {
    public :
    Vec3(int x = 0, int y = 0, int z = 0){this->x = x; this->y = y; this->z=z;}

    template <typename Iterator>
    Vec3(const Iterator &begin,const Iterator &end){
        assert(end-begin <4);
            this->x =*begin;
            this->y =*(begin+1);
            this->z =*(begin+2);
    }

    static Vec3 axis(int i) {
        switch(i){
            case 0:
                return Vec3(1, 0, 0);
            case 1:
                return Vec3(0, 1, 0);
            case 2:
                return Vec3(0, 0, 1);
            default:
                throw out_of_range("Index must be 0, 1, or 2.");
        }
    }

    int& operator[](size_t i){
        if (i == 0) return this->x;
        else if (i == 1) return this->y;
        else if (i == 2) return this->z;
        else throw out_of_range("Index must be 0, 1, or 2.");
    }

    int operator[](size_t i) const{
        if (i == 0) return this->x;
        else if (i == 1) return this->y;
        else if (i == 2) return this->z;
        else throw out_of_range("Index must be 0, 1, or 2.");
    }

    Vec3 operator+(const Vec3& other) const {
        return Vec3(x + other.x, y + other.y, z + other.z);
    }

    Vec3& operator+=(const Vec3& b) {
        x += b.x;
        y += b.y;
        z += b.z;
        return *this;
    }

    int getX() const{
        return this->x;
    }
    int getY() const{
        return this->y;
    }
    int getZ() const{
        return this->z;
    }
    private :
    int x;
    int y;
    int z;
};

ostream& operator<<(ostream& os ,const Vec3& v){return os<<"("<<v.getX()<<","<<v.getY()<<","<<v.getZ()<<")";}

int main() {
    Vec3 v1{};
    cout << "v1 = " << v1 << endl;

    v1[2] = 2;
    cout << "v1 = " << v1 << endl;

    array a{1., 3., 2.};
    const Vec3 v2(a.begin(),a.end());
    cout << "v2 = " << v2 << endl;

    for (size_t i = 0; i < 3; ++i)
        cout << "v2[" << i << "] = " << v2[i] << ((i < 2) ? ", " : "\n");

    vector b{4., 2., 5.};
    Vec3 v3(b.begin(), b.end());
    cout << "v3 = " << v3 << endl;

    Vec3 v4 = v2 + v3;
    cout << "v4 = " << v4 << endl;

    v4 += v2;
    cout << "v4 = " << v4 << endl;

    Vec3 x = Vec3::axis(0);
    cout << "x = " << x << endl;
    Vec3 y = Vec3::axis(1);
    cout << "y = " << y << endl;
    Vec3 z = Vec3::axis(2);
    cout << "z = " << z << endl;
}