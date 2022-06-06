#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string* str;
string* stc;

int radi(string A[], int a, int b, int c){
        int j = 0, k = 0, m = 0;
    for (int i = 0 ; i < a ; i++)
    {
        if (A[i][b-c] == 'a')
        {
            str[j++] = A[i];
        }
        else // (A[i][b-c] == 'b')
        {
              stc[k++] = A[i];
        }
    }
    
    for ( int i = 0 ; i < j ; i++){
        A[i] = str[i];
    }
    
    for ( int i = j; i < j + k ; i++){
        A[i] = stc[m++];
    }
}

int main() {
    ifstream fin("radixsort.in");
    ofstream fout("radixsort.out");
    int a ,b ,c;

    fin >> a;
    fin >> b;
    fin >> c;
    string arr[a];
    str = new string[a];
    stc = new string[a];
    
    for (int i = 0; i < a; i++)
    {
        fin >> arr[i];
    }

   for (int i = 1; i <= c; i++)
   {
       radi(arr,a,b,i);
   }

    for (int i = 0; i < a; i++)
    {
        fout << arr[i]<< "\n";
    }
       return 0;
}
