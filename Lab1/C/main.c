#include <stdio.h>
#include <stdlib.h>

int max(int a, int b);
int a[1007][1007];

int main(){
    FILE* fin;
    FILE* fout;
    
    int h,c,i,j;
    fin=fopen("turtle.in","r");
    fout=fopen("turtle.out","w");
    fscanf(fin,"%d %d", &h, &c);
    for(i=1;i<=h;i++){
        for (j=1;j<=c;j++){
            fscanf(fin,"%d", &a[i][j]);
        }
    }
    
    for (i=h; i>=1;i--){
        for(j=1;j<=c;j++){
            a[i][j]+=max(a[i+1][j],a[i][j-1]);
        }
    }
    
    
    fprintf(fout,"%d", a[1][c]);
    fclose(fin);
    fclose(fout);
    return 0;
 }
int max(int a, int b) {
    if(a>b) return a;
    return b;
}

