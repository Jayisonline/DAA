#include <bits/stdc++.h>

using namespace std;

float power(float x, int n){

    float a;

    if (n == 0)return 1;

    a = power(x, n/2);

    if (n&1){
        return a*a*x;
    } else {
        return a*a;
    }
}

int main(){

    int n; float x; cin >> x >> n;

    clock_t start;
    clock_t end;

    start = clock();

    cout << power(x, n) << '\n';

    end = clock();

    double timetaken = (end-start)/(double)CLOCKS_PER_SEC;

    cout << fixed << timetaken << '\n';

}

// This Algorithum works in O(logn) complextity