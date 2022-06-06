#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#define L 10002

struct Bracket {
    char bracket;
    struct Bracket* link;
};

Bracket* top = nullptr;         /// a pointer with null value

bool isEmpty() {
    return top == nullptr;
}

void push(char bracket) {
    Bracket* b = new Bracket();
    b->bracket = bracket;
    b->link = top;
    top = b;
}

void pop() {
    top = top->link;
}

char gettop() {
    return top->bracket;
}

bool BS(char* str) {  /// bracket sequence
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(' || str[i] == '[') {
            push(str[i]);
            continue;
        }
        if (isEmpty())
            return false;
        if ((gettop() == '(' && str[i] == ')') || (gettop() == '[' && str[i] == ']')) {
            pop();
        }
        else return false; 
    }
    return isEmpty();
}

int main() {
    ifstream fin("brackets.in");
    ofstream fout("brackets.out");
    char str[L];
    while (fin.getline(str, L)) {
        if (BS(str))
            fout << "YES" << "\n";
        else
            fout << "NO" << "\n";
        top = nullptr;
    }

    return 0;
}
