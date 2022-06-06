#include <stdio.h>
#include <stdbool.h>
#define M 1000001

FILE *fin;
FILE *fout;

int queue[M];
int front = -1;
int rear = -1;

bool isFull(){
    if (rear >= M) {
        return true;
    }else
        return false;
}

bool isEmpty(){
    if (rear == front) {
        return true;
    }else
        return false;
}

void enqueue(int a){
    if (!isFull()) {
        rear = rear +1;
        queue[rear] = a;
    }
}

int dequeue(){
    int a=0;
    if (!isEmpty()) {
        front = front + 1;
        a = queue[front];
    }return a;
}

int main() {
    fin = fopen("queue.in", "r");
    fout = fopen("queue.out", "w");
    int m;
    fscanf(fin, "%d", &m);
    char c;
    int number;
    for (int i=0; i<2*m; i++) {
        fscanf(fin, "%c", &c);
        if (c == '+') {
            fscanf(fin, "%d", &number);
            enqueue(number);
        }else if(c == '-'){
            fprintf(fout, "%d\n", dequeue());
        }
    }
    return 0;
}
