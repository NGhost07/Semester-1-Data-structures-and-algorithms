#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int a[], int n, int i){
    int left = 2*i+1;
    int right = 2*i+2;
    int largest = i;
    // left child is greater than root
    if (left<n && a[left]>a[largest]) {
        largest = left;
    }
    // right child is greater than root 
    if (right<n && a[right]>a[largest]) {
        largest = right;
    }
    if (i!=largest) {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}

void buildHeap(int a[], int n){ // build the heap
    for (int i=n/2-1; i>=0; i--) {
        heapify(a, n, i);
    }
}

void heapSort(int a[], int n){
    buildHeap(a, n);
    for (int i = n-1; i>0; i--) {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

int main(int argc, const char * argv[]) {
    int n;
    FILE *fin;
    FILE *fout;
    fin = fopen("sort.in", "r");
    fout = fopen("sort.out", "w");
    fscanf(fin, "%d", &n);
    int a[n];
    for (int i=0; i<n; i++) {
        fscanf(fin, "%d", &a[i]);
    }
    fclose(fin);
    heapSort(a, n);
    for (int i=0; i<n; i++) {
        fprintf(fout, " %d ", a[i]);
    }
    fclose(fout);
    return 0;
}
