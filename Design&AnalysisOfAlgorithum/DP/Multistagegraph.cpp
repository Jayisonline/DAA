#include <bits/stdc++.h>
using namespace std;
int c[100][100];

int cost[100], d[100], path[100];


int main(){

    int n, stages = 4;
    // cout << "Number of Edges : ";
    cin >> n >> stages;

    for (int i =0; i < n; i++){
        int x, y, z; cin >> x >> y >> z;
        c[x][y] = z;
    }

    cost[n] = 0;

    for (int i = n-1; i >=1; i--){
        int min = INT_MAX;
        for (int k = i+1; k <= n; k++){

            if (c[i][k]!=0 && c[i][k]+cost[k] < min){
                min = c[i][k]+cost[k];
                d[i] = k;
            }
        }
        cost[i] = min;
        // cout << cost[i] << ' ';

    }

    path[1]  =1;
    path[stages] = n;

    for (int i =2 ; i <= stages; i++){
        path[i] = d[path[i-1]];
       
    }

    for (int i = 1; i <= stages; i++){
        cout << path[i] << ' ';
    }
    cout << '\n';

    



}


// Average case Complexity for Multistage graph is O(E)
// In worst case E = n*(n-1)/2, then Complexity becomes O(n^2)