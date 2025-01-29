//
// Created by Aryeth on 29/01/2025.
//
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

int main() {
    string s = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Phasellus facilisis at dolor eget congue. Duis in lacus placerat ante consectetur tempor. Aliquam lorem nunc, laoreet quis feugiat accumsan, vulputate vitae justo.";
    cout << transformer(s,"abcdefgh.!,:","fghabcde!,:.") << endl;
    cout << s << endl;
    cout << transformer(s,"fghabcde!,:.","abcdefgh.!,:") << endl;
    cout << s << endl;
}