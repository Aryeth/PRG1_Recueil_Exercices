//
// Created by Aryeth on 31/12/2024.
//

#include <array>
#include <iostream>
using namespace std;

class Stack {
public:
    Stack() : top(-1), size(0) {};

    int top;
    int size;
    array<int,10> data{};

    void push(int value) {
        if (size < 10) {
            data[++top] = value;
            size++;
        }
    }

    void pop() {
        if(size>0) {
            data[top--] = 0;
            size--;
        }
    }

    int getVal(int index) {
        return(data[index]);
    }
};

void push(Stack& s, int value) {
    s.push(value);
}
void pop(Stack& s) {
    s.pop();
}

bool empty(Stack s) {return s.top==-1;}
bool full(Stack s) {return s.top==9;}

int top(Stack s) { return s.getVal(s.top);}
int size(Stack s) {return s.size;}

void display(Stack s) {
    cout << "size : " << s.size << endl;

    cout << "data : [";
    for(int i = 0; i<s.size; i++) {
        int val = s.getVal(i);
        if (val>0) cout << val << ", ";
    }

    int val = s.getVal(s.size);
    if (val>0) cout << val;
    cout << "]" << endl;
}

int main() {

    Stack s;
    int i = 1;

    display(s);
    cout << endl;

    while (not full(s)) {
        push(s, i*=2);
    }

    cout << "top  : " << top(s)  << endl;
    cout << "size : " << size(s) << endl;
    cout << endl;

    display(s);
    cout << endl;

    while (not empty(s)) {
        pop(s);
    }

    display(s);
    cout << endl;
}