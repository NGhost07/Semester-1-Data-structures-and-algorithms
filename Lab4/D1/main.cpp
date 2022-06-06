#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("postfix.in");
ofstream fout("postfix.out");

struct symbol {
    int data;
    struct symbol *next;
};

struct symbol *top;

void push(int val) {
    symbol* p = new symbol();
    p->data = val;
    p->next = top;
    top = p;
}

int main() {
    int calc;
    char ch;
    while (fin.get(ch)) {
        if (ch >= 48 && ch <= 57) {
            push(ch - 48);
        }
        else if (ch == '+') {
            calc = top->data + top->next->data;
            top->next->data = calc;
            top = top->next;
        }
        else if (ch == '-') {
            calc = top->next->data - top->data;
            top->next->data = calc;
            top = top->next;
        }
        else if (ch == '*') {
            calc = top->data * top->next->data;
            top->next->data = calc;
            top = top->next;
        }
    }
    fout << top->data;
    return 0;
}
