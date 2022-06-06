#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
    ifstream fin("garland.in");
    ofstream fout("garland.out");
    int n;
    fin >> n;
    double A;
    fin >> A;
    double l = 0 , r=A , last = -1;

    while (true){
        double mid = (l + r) / 2;
        if (l == mid || r == mid){
            break;
        }
        double p = A;
        double c = mid;
        bool aboveZero = c > 0;
        for (int i = 3; i <= n; i++){
            double next = 2 * c - p + 2;
            aboveZero &= next >= 0;
            p = c;
            c = next;
        }
        if (aboveZero){
            r = mid;
            last = c;
        }
        else{
            l = mid;
        }
    }fout << fixed << setprecision(2) << last;
    return 0;
}
