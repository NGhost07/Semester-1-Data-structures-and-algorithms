#include <stdio.h>
#include <stdlib.h>
int n;
int a[70100];
FILE *fin;
FILE *fout;
void building(int *a, int h) {
    if (h == 3) {
        a[1] = 1;
        a[2] = 3;
        a[3] = 2;
        return;
    }
    if (h > 3){
        building(a, h-1);
    }
    a[h] = a[(1+h)/2];
    a[(1+h)/2] = h;
}
int main()
{
    fin = fopen("/Users/tranhoangnam/Desktop/Алгоритмы и структуры данных/Lab2/2D/antiqs.in", "r");
    fout = fopen("/Users/tranhoangnam/Desktop/Алгоритмы и структуры данных/Lab2/2D/antiqs.out", "w");
    fscanf(fin, "%d", &n);
    building(a, n);
    for(int i=1; i<=n; ++i){
        fprintf(fout, "%d ", a[i]);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
