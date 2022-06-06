#include <stdio.h>
#include <math.h>
FILE *fin;
FILE *fout;
int  x ;
float arr[99999];
int location[99999];
int main(){
    fin = fopen("sortland.in","r");
    fscanf(fin,"%d",&x);
    for(int i=1; i<=x; ++i) {
        fscanf(fin, "%f", &arr[i]);
        location[i] = i;
    }
    for(int i=1; i<=x; ++i){
        for(int j=i+1; j<=x; ++j){
            if (arr[i] > arr[j]){
                float tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                int tmp1 = location[i];
                location[i] = location[j];
                location[j] = tmp1;
            }
        }
    }
    fclose(fin);
    
    fout = fopen("sortland.out", "w");
    fprintf(fout, "%d %d %d", location[1], location[(x+1)/2], location[x]);
    fclose(fout);
    return 0;
}
