#include <fstream>
#include <iostream>
using namespace std;
 
ifstream fin("/Users/tranhoangnam/Desktop/Алгоритмы и структуры данных/Lab4/4E1/binsearch.in");
ofstream fout("/Users/tranhoangnam/Desktop/Алгоритмы и структуры данных/Lab4/4E1/binsearch.out");
 
int BSearchRight(int arr[], int le, int ri, int x)
{
    int result = -1;
    while (le <= ri) {
        int mid = (le + ri) / 2;
        if (arr[mid] < x){
            le = mid + 1;
        }
        else if (arr[mid] > x){
            ri = mid - 1;
        }
        else{
            result = mid+1;
            le = mid + 1;
        }
    }return result;
}
 
int BSearchLeft(int arr[], int le, int ri, int x){
    int result = -1;
    while (le <= ri){
        int mid = (le + ri) / 2;
        if (arr[mid] < x){
            le = mid + 1;
        }
        else if (arr[mid] > x){
            ri = mid - 1;
        }
        else{
            result = mid;
            ri = mid - 1;
        }
    }return result;
}
 
void binSearch(int arr[], int le, int ri, int x)
{
    int left = BSearchLeft(arr, le , ri, x);
    int right = BSearchRight(arr, le, ri, x);
    fout << left << " " << right << "\n";
}
 
int main(void)
{
    int N;
    fin >> N;
    int arr[N];
    for (int i = 0; i < N; i++) {
        fin >> arr[i];
    }
    int m;
    fin >> m;
    int arr1[m];
    for (int i = 0; i < m; i++) {
        fin >> arr1[i];
        binSearch(arr, 1, N, arr1[i]);
    }
    return 0;
}
