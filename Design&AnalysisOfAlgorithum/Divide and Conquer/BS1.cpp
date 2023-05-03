//Binary Search with Iterative method


#include <bits/stdc++.h>
using namespace std;


int main(){

    int n;
    cin >> n;
    int a[n], target;


    for (int i =0; i < n; i++) {
        cin >> a[i];
    }

    cin >> target;

    sort(a, a+n);

    int l = 0, r = n-1, ans = -1;

    while(l <= r){
        int mid = (l+r)/2;

        if (a[mid] < target)
            l = mid+1;
        else if (a[mid] > target)
            r = mid-1;
        else{
            ans = mid;
            break;
        }
    }

    // cout << ans << '\n';

    if (ans != -1)
        cout <<  "Element Found on Index : " << ans << '\n';
    else
        cout << "Not Found\n";

}


// Time Complexity is O(log2n)B