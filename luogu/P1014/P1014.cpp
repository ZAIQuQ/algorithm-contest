#include <iostream>
#include <algorithm>
using namespace std;
// Å¼Êý´ÓÓÒÍù×ó
// ÆæÊý´Ó×óÍùÓÒ
int n;
int sum;
int main(){
    cin >> n;
    register int idx = 1;
    sum = 0;
    while(sum < n)
        sum += idx++;
    sum -= (idx - 1);
    if((idx-1) % 2){
        cout << idx + sum - n << '/' << n - sum << endl;
    }else{
        cout <<  n - sum << '/' << idx + sum - n << endl;
    }
    return 0;
}