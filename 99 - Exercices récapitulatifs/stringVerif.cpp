//
// Created by Aryeth on 29/01/2025.
//
#include <array>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int transformer(string s, const string& base, const string& cypher) {
    if(base.size() != cypher.size()) {
        std::cerr<<"pas la même taille";
        return {};
    }
    int count = 0;
    vector<std::pair<char, char>> pseudoMap;
    for(size_t i = 0; i<base.size(); i++) {
        pseudoMap.push_back({base[i], cypher[i]});
    }
    for(size_t i = 0; i<s.size(); i++) {
        for(const auto& baseC : pseudoMap) {
            if(s[i] == baseC.first) {
                s[i] = baseC.second;
                ++count;
                break;
            }else if(tolower(s[i]) == tolower(baseC.first)) {
                if(isupper(s[i])) {
                    s[i] = toupper(baseC.second);
                }else {
                    s[i] = tolower(baseC.second);
                }
                ++count;
                break;
            }
        }
    }
    return count;
}
bool verifier(string_view a, string_view b) {
    std::array<int, 26> alphabeta{};
    std::array<int, 26> alphabetb{};
    for(char c : a) {
        ++alphabeta[size_t(tolower(c))-size_t('a')];
    }
    for(char c : b) {
        ++alphabetb[size_t(tolower(c))-size_t('a')];
    }
    for(int i : alphabeta) {
        if(i>1) {
            return false;
        }
    }
    for(int i : alphabetb) {
        if(i>1) {
            return false;
        }
    }

    if(alphabeta==alphabetb) {
        return true;
    }

    return false;
}

void tester(string_view a, string_view b) {
    cout << '\"' << a << "\" "
         << (verifier(a, b) ? "" : "in") << "compatible avec "
         << '\"' << b << '\"' << endl;
}

int main() {
    tester("abcdef","FEDBAC");
    tester("abcdef","xyz123");
    tester("abcA","cAba");
}