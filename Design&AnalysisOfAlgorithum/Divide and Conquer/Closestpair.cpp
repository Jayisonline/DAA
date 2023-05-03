// Shortest Distance Between two points on 2D graph

#include<bits/stdc++.h>
using namespace std;

int cnt =0;

int x, y, a, b;

double distance(pair<int, int> a, pair<int, int> b){

    // cout << sqrt(abs(a.first-b.first)*abs(a.first-b.first) + abs(a.second -b.second)*abs(a.second- b.second)) << ' ';

    if (a == b)return FLT_MAX;

    
    return sqrt((a.first-b.first)*(a.first-b.first) + (a.second -b.second)*(a.second- b.second));
    
    // if (dist!=0.0)
    // return dist;

    // return INT_MAX*1.000;
}

float closest(vector<pair<int, int>> &strip, int size, float d){

    float min = d;

    sort(strip.begin(), strip.end(), [](pair<int, int> &a, pair<int, int> &b){
        return a.second > b.second;
    });

    
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].second - strip[i].second) < min; ++j)
            if (distance(strip[i],strip[j]) < min){
                min = distance(strip[i], strip[j]);
                x = strip[i].first;
                y = strip[i].second;
                a = strip[j].first;
                b = strip[j].second;

                // printf("%d %d %d %d\n", x, y, a, b);
            }


    return d;

}





float bruteforce(vector<pair<int, int>> &p, int l, int r){

    float mini = FLT_MAX;

    for (int i = l; i <= r; i++){
        for (int j = l+1; j <= r; j++){
            float ans = distance(p[i], p[j]);
            if (ans < mini){
                mini = ans; 
                x = p[i].first;
                y = p[i].second;
                a = p[j].first;
                b = p[j].second;
            }
        }
    }

    return mini;
}


float find(vector<pair<int, int>> p, int l, int r){

    if (r-l+1 <= 3)
       return bruteforce(p, l, r);

    int mid = (l+r)/2;
    pair<int, int> midpoint = p[mid];

    float dl = find(p, l, mid);
    float dr = find(p, mid+1, r);

    float d = min(dl, dr);

    vector<pair<int, int>> strip;

    int j = 0;

    for (int i =0; i < r+1; i++){
        if (abs(p[i].first - midpoint.first) < d){
            strip.push_back(p[i]);
            j++;
        }
    }


    return min(d, closest(strip, j, d));

}

int main(){

    int n; cin >> n;
    vector<pair<int, int>> p(n);

    for (int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;

    sort(p.begin(), p.end());

    cout << find(p, 0, n-1) << '\n';

    printf("%d %d %d %d\n", x, y, a, b);

    // cout << cnt << '\n';
    // find(p, n/2+1, n-1);

}



// T(n) = 2T(n/2) + O(n) + O(nLogn) + O(n) 
// T(n) = 2T(n/2) + O(nLogn) 
// T(n) = T(n x Logn x Logn)