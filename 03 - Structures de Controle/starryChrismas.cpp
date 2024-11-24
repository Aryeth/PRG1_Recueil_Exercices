//
// Created by leobe on 30/09/2024.
//

// in example, 13 stars for 7lines

#include <iostream>
#include <numeric>
using namespace std;

int main() {

    int size = -1;

    //Asking user for size
    while(size <= 0) {
        cout << "Enter the size of your tree : " ;
        cin >> size;
        cout << endl;
    }


    for(int i = 0; i < size; i++) {
        //Calculate how much spaces are needed for 1st line
        int spaceSize = size - i - 1;
        //adds that much blankspaces
        for(int j = 0; j < spaceSize; j++) {
            cout <<" ";
        }
        //adds 1 star per line (left side)
        for(int k = 0; k <= i; k++) {
            cout << "*";
        }
        // adds 1 star per line minus 1 (right side)
        for(int k = 0; k < i; k++) {
            cout << "*";
        }
        cout << endl;
    }


    return 0;
}