#include <iostream>
#include <fstream>

using namespace std;

string* str;

void mergeSort(string a[], int l, int r, int size, int x)
{
    if (l < r)
    {
        int m = (l + r) / 2;

        mergeSort(a, l, m, size, x);
        mergeSort(a, m + 1, r, size, x);

        int i = 0, j = 0;


        while (l + i <= m && m + 1 + j <= r)
        {
            if (a[l + i][size - x] <= a[m + 1 + j][size - x])
            {
                str[i + j] = a[l + i];
                i++;
            }
            else
            {
                str[i + j] = a[m + 1 + j];
                j++;
            }
        }

        while (l + i <= m)
        {
            str[i + j]  = a[l + i];
            i++;
        }
        while (m + 1 + j <= r)
        {
            str[i + j] = a[m + 1 + j];
            j++;
        }

        for (i = 0; i < r - l + 1; i++)
        {
            a[l + i] = str[i];
        }
    }
}

int main() {
    ifstream open("radixsort.in");
    ofstream close("radixsort.out");
    int a ,b ,c;
    open >> a;
    open >> b;
    open >> c;
    string arr[a];
    str = new string[a];
    for (int i = 0; i < a; i++)
    {
        open >> arr[i];
    }

    for (int i = 1; i <= c; i++)
    {
        mergeSort(arr, 0, a - 1, b, i);
    }

    for (int i = 0; i < a; i++)
    {
        close << arr[i] << "\n";
    }
    return 0;
}
