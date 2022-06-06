#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Size 1000010
 
FILE *fin;
FILE *fout;
 
struct node{
    long int val;
    struct node *next;
};
 
struct node *hTable[Size];

void initbuckets(){
    for (int i=0; i<Size; i++) {
        hTable[i] = NULL;
    }
}
 
struct node* newNode(int x){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->val = x;
    temp->next = NULL;
    return temp;
}

bool exists (int x){
    int key = abs(x%Size);
    for (struct node* p = hTable[key]; p!=NULL; p=p->next) {
        if (p->val == x) {
            return true;
        }
    }return false;
}

void insert(int x){
    if (exists(x)) {
        return;
    }else{
        int key = abs(x%Size);
        if (hTable[key] == NULL) {
            hTable[key] = newNode(x);
            return;
        }else{
            struct node* p = newNode(x);
            p->next = hTable[key];
            hTable[key] = p;
            return;
        }
    }
}

void deleteNode(int x){
    if (!exists(x)) {
        return;
    }else{
        int key = abs(x%Size);
        if (hTable[key]->val == x) {
            hTable[key] = hTable[key]->next;
        }else{
            hTable[key]->next = NULL;
        }
    }
}

int main() {
    fin = fopen("set.in", "r");
    fout = fopen("set.out", "w");
    int x; char c;
    while ((c=fgetc(fin)) != EOF) {
        if (c == 'i') {
            while ((fgetc(fin)) != ' ');
            fscanf(fin, "%d", &x);
            insert(x);
        }
        else if (c == 'e'){
            while ((fgetc(fin)) != ' ');
            fscanf(fin, "%d", &x);
            if (exists(x)==true) {
                fprintf(fout, "true\n");
            }else if (exists(x)==false){
                fprintf(fout, "false\n");
            }
        }
        else if (c == 'd'){
            while ((fgetc(fin)) != ' ');
            fscanf(fin, "%d", &x);
            deleteNode(x);
        }
    }
    return 0;
}
///Users/tranhoangnam/Desktop/Алгоритмы и структуры данных/lab6/6A/6A/
