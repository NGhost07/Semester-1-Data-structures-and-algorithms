#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int n;
char **a, **b;
bool greater(int x, int y) {
    if (strcmp(a[x], a[y]) != 0) return (strcmp(a[x], a[y]) > 0);
    return (x > y);
}

/*void swap(char *c, char *d){
    char temp = *c;
    *c = *d;
    *d = temp;
}

char partition(char ** a, int low, int high){
    char *pivot = a[high];
    int left = low;
    int right = high-1;
    while (true) {
        while (left <= right && !greater(*a[left], *pivot)) {//a[left] < pivot
            left ++;
        }
        while (right >= left && greater(*a[right], *pivot)) {// a[right] > pivot
            right --;
        }
        if (left>=right) {
            break;
        }
        swap(a[left], a[right]);
        left ++;
        right --;
    }
    swap(a[left], a[high]);
    return left;
}

void quickSort(char **a, int low, int high){
    if (low<high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi-1);
        quickSort(a, pi+1, high);
    }
}*/

void merge(char **arr, int l1, int r1, int l2, int r2) {
    char **t1, **t2;
    t1 = (char **)malloc( (r2-l1+1) * sizeof(char));
    t2 = (char **)malloc( (r2-l1+1) * sizeof(char));
    int i1 = l1, i2 = l2;
    for(int i = 0; i<r2-l1+1; ++i) {
        t1[i] = (char *)malloc( 11 * sizeof(char) );
        t2[i] = (char *)malloc( 11 * sizeof(char) );
        if (i1 > r1) {
            t1[i] = arr[i2];
            t2[i] = b[i2];
            i2 ++;
            continue;
        }
        if (i2 > r2) {
            t1[i] = arr[i1];
            t2[i] = b[i1];
            i1 ++;
            continue;
        }
        if (greater(i2, i1)) {
            t1[i] = arr[i1];
            t2[i] = b[i1];
            i1 ++;
            continue;
        }
        t1[i] = arr[i2];
        t2[i] = b[i2];
        i2 ++;
    }
    int id = 0;
    for(int i = l1; i<=r2; ++i) {
        arr[i] = t1[id];
        b[i] = t2[id];
        id ++;
    }
}
void mergeSort(char **arr, int le, int ri) {
    if (le == ri) return ;
    int mi = le + (ri - 1)/2;
    mergeSort(arr, le, mi);
    mergeSort(arr, mi+1, ri);
    merge(arr, le, mi, mi+1, ri);
}
int main(int cnt, char **args) {
    FILE *fi = fopen("/Users/tranhoangnam/Desktop/Алгоритмы и структуры данных/Lab2/2B/race.in", "r");
    FILE *fo = fopen("/Users/tranhoangnam/Desktop/Алгоритмы и структуры данных/Lab2/2B/race.out", "w");
    fscanf(fi, "%d", &n);
    a = (char **)malloc(100100 * sizeof(char));
    b = (char **)malloc(100100 * sizeof(char));
    for(int i=1; i<=n; ++i) {
        a[i] = (char *)malloc(11 * sizeof(char));
        b[i] = (char *)malloc(11 * sizeof(char));
        fscanf(fi, "%s %s", a[i], b[i]);
    }
    quickSort(a, 1, n);
    for(int i=1; i<=n; ++i) {
        fprintf(fo, "=== %s ===\n", a[i]);
        fprintf(fo, "%s\n", b[i]);
        while (i < n && strcmp(a[i+1], a[i]) == 0) { fprintf(fo, "%s\n", b[i+1]); i++; }
    }
}
