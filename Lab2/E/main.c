#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int a[30000010], k, n, A, B, C;
int quickSelect(int *arr, int lo, int hi) {
    int pivot = a[lo + rand () % (hi - lo + 1)];
    int i = lo - 1, smaller = 0, equal = 0;
    
    for(int j = lo; j <= hi; ++j) if (arr[j] < pivot) {
        smaller ++;
        i ++;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    for(int j = lo; j <= hi; ++j) if (arr[j] == pivot) {
        equal ++;
        i ++;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    if ( smaller < k && k <= smaller+equal ) return pivot;
    if ( smaller >= k ) return quickSelect(arr, lo, i-equal);
    k -= smaller + equal;
    return quickSelect(arr, i+1, hi);
}

int main(){
    FILE *fi = fopen("kth.in", "r");
    FILE *fo = fopen("kth.out", "w");
    srand(time(NULL));
    fscanf(fi, "%d %d", &n, &k);
    fscanf(fi, "%d %d %d %d %d", &A, &B, &C, &a[1], &a[2]);
    
    for(int i=3; i<=n; ++i) {
        a[i] = a[i-2] * A + a[i-1] * B + C;
    }
    
    fprintf(fo, "%d", quickSelect(a, 1, n));
}
