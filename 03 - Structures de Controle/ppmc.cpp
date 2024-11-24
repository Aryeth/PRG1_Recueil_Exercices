//
// Created by leobe on 26/09/2024.
//

#include <iostream>
#include <numeric>
using namespace std;

int main() {

    int a = -1;
    int b = -1;


    while(a<=0 || b<=0) {
        cout << "Enter 2 positive numbers" << endl;
        cin >> a >> b ;
    }
    cout << lcm(a,b) << endl;

    return 0;
}