#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 5e3 + 10;
int l, n, arr[N];
int minarr[N], maxarr[N];
bool cmpmin(int a, int b){
    return a > b;
}
bool cmpmax(int a, int b){
    return a > b;
}
int main(){
    cin >> l >> n; 
    for(int i = 0; i < n; i++){
        scanf("%d", arr + i);
        minarr[i] = min(arr[i], l + 1 - arr[i]);
        maxarr[i] = max(arr[i], l + 1 - arr[i]);
    }
    sort(minarr, minarr+n, cmpmin);
    sort(maxarr, maxarr+n, cmpmax);
    cout << minarr[0] << " " << maxarr[0] << endl;
    return 0;
}