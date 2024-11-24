//
// Created by leobe on 10/10/2024.
//
#include <iostream>
#include <fstream>
#include <ios>
using namespace std;

string asking();
bool userDoneTest();

int main() {
  string filename;
  ofstream file;
  //Ask for file name, open in append mode (creates a file if nonexistant)
  filename = asking();
  file.open(filename+".txt", ios::app);

  bool isUserDone = false;

  // as long as user doesnt answer y to the question, can add stuff init
  while(!isUserDone){
    cout << "entrez du texte :";
    string toWrite;
    cin.ignore();
    getline(cin, toWrite);
    cin.clear();
    file << toWrite << endl;
    isUserDone = userDoneTest();
  }

  file.close();

  return 0;
 }

 string asking(){
  cout << "Insérez le nom de sortie :" ;
  string filename;
  cin >> filename;
  cout << endl;
  cin.clear();
  return filename;
 }
bool userDoneTest() {
  //Asks user if he wants to write another line
  //Bad user input gestion included
  while(true) {
    try {
      cout << endl <<"Are you done ? (y/n) : " << endl;
      string done;
      cin >> done;
      cin.clear();
      if (done == "y") {
        return true;
      }
      if (done == "n") {
        return false;
      }
      throw 400;
    }
    catch (...) {
      cout << "Please answer with y or n";
    }
  }
}
