#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int stack[100];
int top =-1;

bool isFull(){
    if (top >= 100) {
        return true;
    }else
        return false;
}
void push(int number){
    if (!isFull()) {
        top = top +1;
        stack[top] = number;
    }
}

int change (char c){
    return (int)c-48;
}

int calcutate(char *s){
    for (int i=0; i<(int)strlen(s); i++) {
        if (s[i]>=48 && s[i] <= 57) {
            push(change(s[i]));
        }
        if (s[i] == '+') {
            stack[top -1] = stack[top-1] + stack[top];
        }
        if (s[i] == '-') {
            stack[top -1] = stack[top-1] - stack[top];
        }
        if (s[i] == '*') {
            stack[top -1] = stack[top-1] * stack[top];
        }
    }return stack[top];
}

int main() {
    FILE *fin = fopen("/Users/tranhoangnam/Desktop/Алгоритмы и структуры данных/Lab4/4D/postfix.in", "r");
    FILE *fout = fopen("/Users/tranhoangnam/Desktop/Алгоритмы и структуры данных/Lab4/4D/postfix.out", "w");
    char s[100];
    fgets(s, 100, fin);
    fprintf(fout, "%d", calcutate(s));
    return 0;
}
