#include <iostream>
#include <fstream>
#include <cstring>
#define SIZE 1000000
using namespace std;
ifstream fin("priorityqueue.in");
ofstream fout("priorityqueue.out");
struct Node {
    int data;
    int line;
};

Node queue[SIZE];
int front = -1;
int rear = -1;
int line = 0;

void heapify() {
    int size = rear - front + 1;
    Node variable[size];
    int j = 0;
    for (int i = front; i <= rear; i++) {
        variable[j++] = queue[i];
    }
    for (int i = 1; i < size; i++)
    {
        if (variable[i].data < variable[(i - 1) / 2].data){
            j = i;
            while (variable[j].data < variable[(j - 1) / 2].data){
                swap(variable[j], variable[(j - 1) / 2]);
                j = (j - 1) / 2;
            }
        }
    }
    j = 0;
    for (int i = front; i <= rear; i++) {
        queue[i] = variable[j++];
    }
}

void push(int val) {
    line++;
    if (front == -1)
        front = 0;
    rear++;
    queue[rear].data = val;
    queue[rear].line = line;
}

void extract() {
    line++;
    if (front > rear || front == -1) {
        fout << "*\n";
        front = rear = -1;
        return;
    }
    heapify();
    fout << queue[front].data << "\n";
    front++;
}

void decrease(int someLine, int val) {
    line++;
    for (int i = front; i <= rear; i++) {
        if (queue[i].line == someLine) {
            queue[i].data = val;
        }
    }
}
int main() {
    char charac;
    int val;
    int line;
    while (fin.get(charac)) {
        if (charac != '\n') {
            if (charac == 'p') {            /// p = push function
                while (fin.get() != ' ');
                fin >> val;
                push(val);
            }
            else if (charac == 'e') {              /// e = extract function
                for (int i = 0; i < 10; i++ ) {
                    fin.get(charac);
                }
                extract();
            }
            else if (charac == 'd'){            /// d =  decrease key
                while (fin.get() != ' ');
                fin >> line;
                fin >> val;
                decrease(line, val);
            }
        }
    }
    return 0;
}
