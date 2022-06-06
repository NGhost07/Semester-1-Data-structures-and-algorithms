#include <stdio.h>
#include <stdbool.h>
#define SIZE 1000001

FILE *fin;
FILE *fout;
int stack[SIZE];
int top = -1;

bool isEmpty(){
    if (top == -1) {
        return true;
    }else{
        return false;
    }
}

bool isFull(){
    if (top >= SIZE) {
        return true;
    }else{
        return false;
    }
}

void push(int number){
    if (!isFull()){
        top = top +1;
        stack[top] = number;
    }
}

int pop(){
    int data = 0;
    if (!isEmpty()) {
        data = stack[top];
        top = top -1;
    }return data;
}

int main(){
    fin = fopen("stack.in", "r");
    fout = fopen("stack.out", "w");
    int number;
    int M;
    char c;
    fscanf(fin, "%d",&M);
    for (int i=0; i<2*M; i++) {
        fscanf(fin, "%c", &c);
        if (c == '+') {
            fscanf(fin, "%d", &number);
            push(number);
        }else if(c == '-'){
            fprintf(fout, "%d\n", pop());
        }
    }
    return 0;
}
