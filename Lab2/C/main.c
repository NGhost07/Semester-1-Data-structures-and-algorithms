#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long long AmergeSort(long long arr[], long long temp[], long long l, long long r);

long long merge(long long arr[], long long temp[], long long l, long long m, long long r);

long long mergeSort(long long arr[], long long arraysize){
    long long* temp = (long long*)malloc(sizeof(long long) * arraysize);
    return AmergeSort(arr, temp, 0, arraysize - 1);
}

long long AmergeSort(long long arr[], long long temp[], long long l, long long r){
    long long mid, invcount = 0;
    if (r > l) {
    mid = (r + l) / 2;
    invcount =  AmergeSort(arr, temp, l, mid);
    invcount +=  AmergeSort(arr, temp, mid + 1, r);
    invcount +=  merge(arr, temp, l, mid + 1, r);
    }
    return invcount;
}

long long merge(long long arr[], long long temp[], long long l, long long mid, long long r){
    long long i, j, k;
    long long invcount = 0;

    i = l;
    j = mid;
    k = l;
    while (( i <= mid - 1) && (j <= r)) {
        if ( arr[i] <= arr[j] )
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            invcount = invcount + (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j  <= r)
        temp[k++] = arr[j++];
    for (i = l; i <= r; i++)
        arr[i] = temp[i];

    return invcount;
}

int main()
{
    long long n;
    long long  arr[300100];
    FILE *fin;
    FILE *fout;
    fin = fopen("inversions.in","r");
    fscanf(fin,"%lld", &n);
    for (int i=0 ; i < n ; ++i ){
        fscanf(fin,"%lld",&arr[i]);
    }
    fout = fopen("inversions.out","w");
    fprintf(fout,"%lld",mergeSort(arr,n));
    fclose(fin);
    fclose(fout);
    return 0;
}
