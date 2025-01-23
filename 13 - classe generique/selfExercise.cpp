//
// Created by Aryeth on 04/01/2025.
//

#include <array>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string.h>
#include <vector>

using namespace std;

struct skill {
    char key;
    string name;
    int damage;
};

const array<char, 4> keyChars{'Q','W','E','R'};

class Champion {
public :
    Champion(string nm, int h, int m, int lvl) : name(nm), health(h), mana(m), level(lvl){};

    void setSkills() {
        for(size_t i = 0; i<skills.size(); i++) {
            //todo add a list of champions
            skills[i] = {keyChars[i], "tmp name", 200};
        }
    }

    string getName() {
        return this->name;
    }

    int getHealth() {
        return this->health;
    }

    int getMana() {
        return this->mana;
    }

    int getLevel() const {
        return this->level;
    }

    array<skill, 4> getSkills() {
        return this->skills;
    }

private :
    string name;
    int health;
    int mana;
    int level;
    array<skill, 4> skills{};
};

ostream& operator<<(ostream& out, skill display) {
    out << display.key << " " << display.name << " " << display.damage << "dmg" << endl;
    return out;
}

ostream& operator<<(ostream& out, Champion& champ) {
    out << "Champion name : " << champ.getName() << endl;
    out << "Champion health : " << champ.getHealth() << endl;
    out << "Champion mana : " << champ.getMana() << endl;
    out << "Champion skills : " << endl;
    auto skillset = champ.getSkills();
    for(auto c : skillset) {
        out << c;
    }
    return out;
}

template <typename T>
void extractItem(stringstream &ss, T &item) {
    string temp;
    getline(ss, temp, ','); // Extract till comma
    stringstream(temp) >> item; // Convert to appropriate type
}

vector<Champion> getChamps() {
    ifstream file("C:/Users/leobe/CLionProjects/PRG1_Recueil_Exercices/13 - classe generique/champ.txt");
    string line;
    vector<Champion> champions;

    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string nm;
            int h, m, lv;

            // Use the template to extract each part
            extractItem(ss, nm);
            extractItem(ss, h);
            extractItem(ss, m);
            extractItem(ss, lv);

            champions.emplace_back(nm, h, m, lv);
        }
        file.close();
    } else {
        cerr << "Error opening file: " << strerror(errno) << endl;
    }
    return champions;
}

template <typename T, typename Iterator>
T sumList(Iterator begin1, Iterator end1) {
    T result;
    for(Iterator it = begin1; it!=end1; it++) {
        result += *it;
    }
    return result;
}

int main() {

    vector a{1,2,3,4,5};
    cout<<sumList<int>(a.begin, a.end);


    vector<Champion> pool = getChamps();

    for (size_t i = 0; i<pool.size(); i++) {
        pool[i].setSkills();
        cout << "Champion " << i << " :" <<endl << pool[i] <<endl;
    }

    return 0;
}