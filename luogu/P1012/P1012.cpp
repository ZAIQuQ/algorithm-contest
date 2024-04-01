#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool mycmp (string a, string b){
    return a + b > b + a;           // 表示 ab的字典序先于ba
}
const int N = 25;
int n;
string num[N];
int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> num[i];
    }
    sort(num, num + n, mycmp);
    for (int i = 0; i < n; i++){
        cout << num[i];
    }
    return 0;
}