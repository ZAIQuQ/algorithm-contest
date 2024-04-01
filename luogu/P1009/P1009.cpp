#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const ll P = 1e15;
int n;
struct bint{
    ll big[10];
} cur, ans;
bint operator * (bint a, ll b){
    ll cp = 0;
    ll last_cp = 0;
    bint c({0});
    for (int i = 0; i < 10; i++){
        cp = ( a.big[i] * b + last_cp ) / P;
        if(cp){
            c.big[i] = (a.big[i] * b + last_cp) % P ;
            last_cp = cp;
        }else{
            c.big[i] = a.big[i] * b + last_cp;
            last_cp = 0;
        }
    }
    return c;
}
bint operator + (bint a, bint b){
    bint c({0});
    ll cp = 0, last_cp = 0;
    for (int i = 0; i < 10; i++){
        cp = (a.big[i] + b.big[i] + last_cp) / P;
        if(cp){
            c.big[i] = (a.big[i] + b.big[i] + last_cp) % P;
            last_cp = cp;
        }else{
            c.big[i] = (a.big[i] + b.big[i] + last_cp);
            last_cp = 0;
        }
    }
    return c;
}
int main(){
    cin >> n;
    for (int i = 0; i < 10; i++){
        cur.big[i] = ans.big[i] = 0;
    }
    cur.big[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cur = cur * i;
        ans = ans + cur;
    }
    int i = 9;
    while(!ans.big[i])
        i--;
    cout << ans.big[i--];
    for (; i >= 0;i--){
        printf("%015lld", ans.big[i]);
    }
    return 0;
}