#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define Size 100010

FILE *fin;
FILE * fout;

struct node{
    char data[20];
};

struct node* hTable[Size];

void innit(){
    for (int i=0; i<Size; i++) {
        hTable[i] = NULL;
    }
}

int get_key(char* key){
    int k=0;
    for (int i=0; i<strlen(key); i++) {
        k += (int)key[i]*10+i;
    }return (k-970)%Size;
}

bool search_key(char *key){
    int k = get_key(key);
    if (hTable[k]!=NULL) {
        return true;
    }return false;
}

void put_command(char *key, char* data){
    int k = get_key(key);
    if (search_key(key)) {
        return;
    }else{
        hTable[k].data = data;
    }
}

void get_command(char *key){
    int k = get_key(key);
    if (search_key(key)) {
        fputs(hTable[k]->data, fout);
    }else if (search_key(key)){
        fprintf(fout, "none\n");
    }
}

void delete_command(char *key){
    
}

int main() {
    fin = fopen("/Users/tranhoangnam/Desktop/Алгоритмы и структуры данных/lab6/6B/map.in", "r");
    fout = fopen("/Users/tranhoangnam/Desktop/Алгоритмы и структуры данных/lab6/6B/map.out", "w");
    char *key = (char*)malloc(sizeof(char));
    char *data =(char*)malloc(sizeof(char));
    char c;
    while ((c=fgetc(fin))!=EOF) {
        if (c == 'p') {
            while (fgetc(fin) != ' ');
            fscanf(fin, "%s%s", key, data);
            put_command(key, data);
            puts(key);
            puts(data);
        }
        else if (c == 'g'){
            while (fgetc(fin) != ' ');
            fscanf(fin, "%s", key);
            get_command(key);
        }
        else if (c == 'd'){
            while (fgetc(fin) != ' ');
            fscanf(fin, "%s", key);
            delete_command(key);
        }
    }
    puts(hTable[4360]->data);
    puts(hTable[2233]->data);
    return 0;
}
