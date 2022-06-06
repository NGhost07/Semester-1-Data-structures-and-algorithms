#include <stdio.h>
#include <stdbool.h>

bool checkHeap(int x, int a[]){
    for (int i=(x/2-1); i>=0; i--) {
        if (a[i] > a[2*i+1] || a[i] > a[2*i+2]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    FILE *fin;
    FILE *fiout;
    fin = fopen("isheap.in", "r");
    fiout = fopen("isheap.out", "w");
    fscanf(fin, "%d", &n);
    int a[n];
    for (int i=0; i<n; i++) {
        fscanf(fin, "%d", &a[i]);
    }
    fclose(fin);
    checkHeap(n, a)? fprintf(fiout, "YES") : fprintf(fiout, "NO");
    fclose(fiout);
    return 0;
}
