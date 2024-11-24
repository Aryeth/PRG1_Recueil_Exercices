//
// Created by leobe on 28/10/2024.
// CAGR calculator

#include <iostream>
#include <fstream>
#include <ios>
#include <cmath> // For the pow() function

using namespace std;

// Structure to store each record from the file
struct SPY_marketwatch {
  //Date,Open,High,Low,Close,Volume, for file daily_marketwatch
  string Date;
  double Open;
  double High;
  double Low;
  double Close;
  long long Volume;
};

void read_record()
{
  //struct init
  SPY_marketwatch SPY;

  // File pointer
  fstream FileIn;

  // Open an existing file
  FileIn.open("CSV_CAGR/SPY_daily_marketwatch.csv", ios::in);


  string line, word, temp;

  while (FileIn >> temp)
  {
    // read an entire row and
    // store it in a string variable 'line'
    getline(FileIn, line, '\n');

    // read every column data of a row and
    // store it in a string variable, 'word'
    //TODO store that stuff in the struct
    while(getline(s, word, ',')){

    }


  }
  FileIn.close();
}


// base cagr formula
double calculateCAGR(double startValue, double endValue, int years) {
  return pow(endValue / startValue, 1.0 / years) - 1;
}

int main() {
  double startValue, endValue;
  int years;

  // Getting user input
  cout << "Enter the starting value: ";
  cin >> startValue;
  cout << "Enter the ending value: ";
  cin >> endValue;
  cout << "Enter the number of years: ";
  cin >> years;

  // Calculating CAGR
  double cagr = calculateCAGR(startValue, endValue, years);

  // Displaying the result as a percentage
  cout << "The Compound Annual Growth Rate (CAGR) is: " << cagr * 100 << "%" << endl;

  return 0;
}
