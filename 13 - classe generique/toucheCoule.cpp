//
// Created by Aryeth on 03/01/2025.
//
#include <array>
#include <iostream>

using namespace std;

constexpr int width = 10;
constexpr int height = 10;
constexpr string hori = "-";
constexpr string vert = "|";

enum class Cell{eau, bateau, touche, coule};
const array<char, 4> CellChars{'.', 'B', 'x', 'O'};

template <typename T, size_t width>
using Row = array<T, width>;

template <typename T, size_t width, size_t height>
using Grid = array<Row<T, width>, height>;

template <typename T, size_t width, size_t height>
ostream& operator<<(ostream& os,const Grid<T, width, height>& grid);

int main() {

    const Cell E = Cell::eau;
    const Cell B = Cell::bateau;
    const Cell T = Cell::touche;
    const Cell C = Cell::coule;

    using Game = Grid<Cell, 8, 6>;

    Game game = {{{E, E, E, E, T, T, B, E},
                  {E, E, E, E, E, E, E, E},
                  {E, E, B, E, E, C, E, E},
                  {E, E, T, E, E, C, E, E},
                  {E, E, B, E, E, C, E, E},
                  {E, E, E, E, E, E, E, E}}};
    cout << game << endl;
    return 0;
}

template <typename T, size_t width, size_t heigth>
ostream& operator<< (ostream& os, const Grid<T, width, heigth>& g) {
    os << std::string(width+2, '-') << endl;
    for (const Row<T, width>& r : g) {
        os << '|';
        for (Cell c : r)
            os << CellChars.at((size_t)c);
        os << '|' << endl;
    }
    return os << string(width+2, '-') << endl;
}

