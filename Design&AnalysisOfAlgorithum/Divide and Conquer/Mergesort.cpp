#include <bits/stdc++.h>  
using namespace std;
int a[100010];
int final[100010];

void merge(int arr[], int p, int q, int r) {
  
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
        arr[k] = L[i];
        i++;
        } else {
        arr[k] = M[j];
        j++;
        }
        k++;
    }

    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergesort(int l, int r){
    if (l < r){
        int mid = (r-l)/2+l;

        mergesort(l, mid);
        mergesort(mid+1, r);
        merge(a, l, mid, r);
    }
}



int main(){

    int n; 
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]);

    mergesort(0, n-1);
    // merge(0, 1, 2, 2);

    for (int i =0; i < n; i++)
        cout << a[i] << ' ';
    cout << '\n';
    
    

}