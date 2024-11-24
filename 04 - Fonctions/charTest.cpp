//
// Created by leobe on 14/10/2024.
//
#include <iostream>
#include <string>

using namespace std;


namespace pangram {

bool is_pangram(string phrase);

bool is_pangram(string phrase){
  string alphabet = "abcdefghijklmnopqrstuvwxyz";
  string cleanup = "";

  for(char ch : phrase){
    if (isalpha(ch)) {
      cleanup += tolower(ch);
    }
  }
  for(char charPhrase : cleanup){
    for(char charAlpha : alphabet){
      if(charPhrase == charAlpha){
        erase(alphabet, charAlpha);
      }
    }
  }
  return alphabet.size() == 0;
}
}

int main() {
  cout << pangram::is_pangram("Waltz, bad nymph, for quick jigs vex.");
}

