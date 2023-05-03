#include <bits/stdc++.h>
using namespace std;

int main(){

    int n; cin >> n;
    vector<pair<int, int>> jobs(n), sequence;
    int mx = INT_MIN, max_profit = 0;

    for (int i =0; i < n; ++i){
        cin >> jobs[i].first;  //Profits
    }
    for (int i =0; i < n; ++i){
        cin >> jobs[i].second; //Deadline
        mx = max(mx, jobs[i].second);
    }

    sort(jobs.begin(), jobs.end(), [](pair<int, int> a, pair<int, int> b){
        return a.first > b.first;
    });


    for (int i = 0; i < mx; i++){
        sequence.push_back({jobs[i].first, jobs[i].second});
        max_profit += jobs[i].first;
    }

    for (auto i: sequence){
        cout << i.first << ' ' << i.second << '\n';
    }
    cout << "Max Profit will be : " << max_profit << '\n';

    
}