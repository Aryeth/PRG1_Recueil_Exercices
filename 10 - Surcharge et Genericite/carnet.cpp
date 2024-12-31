//
// Created by leobe on 05/12/2024.
//
#include <array>
#include <iostream>
#include <iomanip>

using namespace std;

struct Date{
  int day;
  int month;
  int year;
};

struct Personne{
  string firstName;
  string lastName;
  Date date;
};

ostream& operator<< (ostream& os, const Date& date) {
  os << date.day << "." << date.month << "." << date.year;
  return os;
}

ostream& operator<< (ostream& os, const Personne& npc) {
  os << left << setw(8) << "prenom" << ": " << npc.firstName  << endl;
  os << left <<setw(8) << "nom" << ": " << npc.lastName    << endl;
  os << left <<setw(8) << "date" << ": "<< npc.date    << endl;
  return os;
}

template <typename T, size_t size>
ostream& operator<< (ostream& os, const array<T, size> a) {
  for(const T& t : a)
    os << t << endl;
  return os;
}

int main(){
  array carnet {Personne{"Jean"s,   "Veuxplus"s, Date{ 7,  4, 1975}},
              Personne{"Alain"s,  "Verse"s,    Date{21, 12, 2018}},
              Personne{"Justin"s, "Ptipeu"s,   Date{ 1,  8, 2023}},
              Personne{"Rémi"s,   "Fasol"s,    Date{17,  5, 1957}}};

  std::cout << carnet << endl;
}