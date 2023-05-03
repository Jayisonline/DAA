//Binary Search with Recursive Method


int BS(int a[], int l, int r, int target){

    if (l > r)return -1;

    int mid = (l+r)/2;

    if (a[mid] < target)
        return BS(a, mid+1, r, target);
    else if (a[mid] > target)
        return BS(a, l, mid-1, target);
    else
        return mid;
}

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

    int ans = -1;

    sort(a, a+n);

    ans = BS(a, 0, n-1, target);

    if (ans != -1)
        cout <<  "Element Found on Index : " << ans << '\n';
    else
        cout << "Not Found\n";

}


// Time Complexity is O(log2n)B