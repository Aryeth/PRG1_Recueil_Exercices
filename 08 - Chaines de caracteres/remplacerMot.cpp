//
// Created by Aryeth on 27/01/2025.
//
#include <string>
#include <utility>
#include <iostream>

using namespace std;

// Ecrivez ici la fonction remplacer_occurences
string remplacer_occurences(const string& txt, string target, string replacement) {
    size_t pos =0;
    string newText = txt;
    while ((pos = newText.find(target, pos)) != string::npos) {
        newText.replace(pos, target.size(), replacement);
        pos += replacement.size();
    }
    return newText;
}

int main() {
    string texte{"Les sanglots longs de violons de l'automne "
                 "bercent mon coeur d'une langueur monotone"};
    cout << texte << endl;
    for (auto p: {pair<string, string>{"on", "ON"},
                  {"on", "o"},
                  {"on", "oin"},
                  {"o", "ooo"}}) {
        cout << remplacer_occurences(texte, p.first, p.second) << endl;
                  }
}