//
// Created by leobe on 09/12/2024.
//

#include <iostream>
#include <array>

using namespace std;

const char* BOOL_EN_FRANCAIS [] = { "faux", "vrai" };

template <typename T, size_t n, typename Func>
void transformer(array<T, n>& a, Func&& func) {
    for (auto& element : a) {
        element = func(element);
    }
}

// Function to display the array
template <typename T, size_t n>
bool afficher(const array<T, n>& a) {
    for (const auto& element : a) {
        cout << element << " ";
    }
    cout << endl;
    return true;
}

//function opposer (generic)
template <typename T>
T opposer(T a) {
    return -a;
}
//opposer (specialisation for booleans)
bool opposer(bool a) {
    return !a;
}


// Overloaded operator<<
template <typename T, size_t n>
ostream& operator<<(ostream& os, const array<T, n>& array) {
    os << "[ ";
    for (size_t i = 0; i < n; ++i) {
            os << array[i];
        switch(i < n - 1) {
        case true:
            os << ", ";
            break;
        }
    }

    os << " ]";
    return os;
}
// for boolean arrays
template <size_t n>
ostream& operator<<(ostream& os, const array<bool, n>& array) {

    os << "[ ";
    for (size_t i = 0; i < n; ++i) {
        const int vraiFaux = array[i];
        os << BOOL_EN_FRANCAIS[vraiFaux];
        switch(i < n - 1) {
        case true:
            os << ", ";
            break;
        }
    }

    os << " ]";
    return os;
}
//for empty arrays
template <typename T>
ostream& operator<<(ostream& os, const array<T, 0>&) {
        os << "[ vide ]";
        return os;
}
//for empty boolean arrays (avoid ambiguity)
ostream& operator<<(ostream& os, const array<bool, 0>&) {
    os << "[ vide ]";
    return os;
}

int main() {

  cout << opposer(42) << " "
       << opposer(42u) << " "
       << boolalpha << opposer(true) << " "
       << opposer(false) << " "
       << opposer(-3.14) << endl;

  array<int,0> a0;                                      cout << a0 << endl;

  array<int, 4> a4 { 1, 2, 3,  4 };                     cout << a4 << endl;
  transformer(a4, opposer<int>);                        cout << a4 << endl;

  array<bool,0> b0;                                     cout << b0 << endl;

  array<bool, 5> b5 { true, false, false, true, true }; cout << b5 << endl;
  transformer(b5, opposer<bool>);                       cout << b5 << endl;

  array<double,0> c0;                                   cout << c0 << endl;

  array<double, 3> c3 { 1.61, 2.72, 3.14 };             cout << c3 << endl;
  transformer(c3, opposer<double>);                     cout << c3 << endl;
}
