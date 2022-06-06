#include <stdio.h>
#include <string.h>
#define SIZE 1000000

FILE *fin;
FILE *fout;

struct NODE{
    int dat;
    int lin;
};

struct NODE queue[SIZE];
int fro = -1;
int rea = -1;
int lin = 0;

void swap(struct NODE a, struct NODE b){
    struct NODE temp = a;
    a = b;
    b = temp;
}

void heapify(){
    int size = rea - fro + 1;
    struct NODE var[size];
    int j = 0;
    for (int i = fro; i <= rea; i++) {
        var[j++] = queue[i];
    }
    for (int i=1; i<size; i++) {
        if (var[i].dat < var[(i-1)/2].dat) {
            j=i;
            while (var[j].dat < var[(j-1)/2].dat) {
                swap(var[j],var[(j-1)/2]);
                j= (j-i)/2;
            }
        }
    }
    j=0;
    for (int i=fro; i<=rea; i++) {
        queue[i] = var[j++];
    }
}

void decrease(int sLi, int val){
    lin ++;
    for (int i = fro; i <= rea; i++) {
        if (queue[i].lin == sLi) {
            queue[i].dat = val;
        }
    }
}

void extract(){
    lin ++;
    if (fro > rea || fro == -1) {
        fprintf(fout, "*\n");
        fro = rea = -1;
        return;
    }
    heapify();
    fprintf(fout, "%d\n", queue[fro].dat);
    fro ++;
}

void push(int val){
    lin ++;
    if (fro == -1) {
        fro = 0;
    }
    rea ++;
    queue[rea].dat = val;
    queue[rea].lin = lin;
}

int main(int argc, const char * argv[]) {
    char s;
    int val = 0;
    int lin = 0;
    fin = fopen("/Users/tranhoangnam/Desktop/Алгоритмы и структуры данных/Lab3/3D/priorityqueue.in", "r");
    fout = fopen("/Users/tranhoangnam/Desktop/Алгоритмы и структуры данных/Lab3/3D/priorityqueue.out", "w");
    while ((s=fgetc(fin))) {
        if (s != '\n') {
            if (s == 'p') {
                while (fgetc(fin) != ' '){
                    fscanf(fin, "%d", &val);
                    push(val);
                }
            }else if (s == 'e'){
                for (int i = 0; i<=10; i++) {
                    fscanf(fin,"%s", &s);
                }
                extract();
            }else if (s == 'd'){
                while (fgetc(fin) != ' '){
                fscanf(fin, "%d", &lin);
                fscanf(fin, "%d", &val);
                }
                decrease(lin, val);
            }
        }
    }
    return 0;
}
