#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define L 10002
#define N 501

char stack[L];
int top =-1;

bool isEmpty(){
    if (top == -1) {
        return true;
    }else{
        return false;
    }
}

bool isFull(){
    if (top >= L) {
        return true;
    }else{
        return false;
    }
}

void push(char c){
    if (!isFull()){
        top = top +1;
        stack[top] = c;
    }
}

bool check(char *s){
    for (int i=0; i<strlen(s); i++) {
        if (s[i] == '(' || s[i] == '[') {
            push(s[i]);
        }
        if (s[i] == ')' || s[i] == ']'){
            if (!isEmpty()) {
                if (s[i] == ')') {
                    if (stack[top] != '(') {
                        return false;
                    }
                }
                if (s[i] == ']') {
                    if (stack[top] != '[') {
                        return false;
                    }
                }
                top = top -1;
            }
            else
                return false;
        }
    }return isEmpty() == true;
}

int main() {
    FILE *fin = fopen("brackets.in", "r");
    FILE *fout = fopen("brackets.out", "w");
    char *s = (char*)malloc(L*sizeof(char));
    int j=0;
    while (!feof(fin) && j<N) {
        j++;
        fgets(s, L, fin);
        if (check(s)) {
            fprintf(fout, "YES\n");
        }else
            fprintf(fout, "NO\n");
    }
    fclose(fin);
    fclose(fout);
    free(s);
    return 0;
}
