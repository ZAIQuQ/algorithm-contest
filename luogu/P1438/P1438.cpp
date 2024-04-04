#include<iostream>
#include<cstring>
using namespace std;
//  修改前
//  a 1 2 3 4 5
// b1 1 1 1 1 1 
// b2 1 0 0 0 0
// T1 1 

//  修改后 
//  a 1 3 6 9 5
// b1 1 2 3 3 -4
// b2 1 1 1 0 -7
// T1
typedef long long ll;
inline int lowbit(int x) { return x & -x; }
int n, m;
const int N = 5e5 + 10;
int a[N];
int b1[N];
int b2[N];
ll tree1[N];
ll tree2[N];   // a_i = b1_1 + b1_2 + ... = k * b2_1 + (k-1) * b2_2 = (k+1)b2_i - b_2_i * i
void AddT1(ll x, ll k){
    for (int i = x; i <= n; i+=lowbit(i)){
        tree1[i] += k;
    }
}
void AddT2(ll x, ll k)
{
    for (int i = x; i <= n; i+=lowbit(i)){
        tree2[i] += (k * x); // 第二个树状数组是带系数i的
    }
}
void AddArr(ll l, ll r, ll A, ll D){
    AddT1(l, A);
    AddT2(l, A);
    if(l == r){
        D = A;
    }else{
        AddT1(l + 1, D - A);
        AddT2(l + 1, D - A);
    }
    if(r+2 <= n){  
        AddT1(r + 2, (A + (r - l) * D));
        AddT2(r + 2, (A + (r - l) * D));
        AddT1(r + 1, -(A + (r - l + 1) * D));
        AddT2(r + 1, -(A + (r - l + 1) * D));
    }else if(r + 1 <= n){
        AddT1(r + 1, -(A + (r - l + 1) * D));
        AddT2(r + 1, -(A + (r - l + 1) * D));
    }
}
void query(int x){
    ll ans = 0;
    for (int i = x; i >= 1; i -=lowbit(i)){
        ans += ((x + 1) * tree1[i] - tree2[i]);
    }
    cout << ans << endl;
}
int main(){
    a[0] = b1[0] = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        scanf("%d", a + i);
        b1[i] = a[i] - a[i - 1];
        b2[i] = b1[i] - b1[i - 1];
        for (int j = i; j <= n; j += lowbit(j)){
            tree1[j] += b2[i];
            tree2[j] += b2[i] * i;
        }   
    }
    // for (int i = 1; i <= n;i++){
    //     cout << tree1[i] << ' ';
    // }
    // cout << endl;
    int op, l, r, A, D;
    while(m--){
        scanf("%d", &op);
        if(op == 1){
            scanf("%d %d %d %d", &l, &r, &A, &D);
            AddArr(l, r, A, D);
        }else{
            // for (int i = 1; i <= n;i++)
            //     cout << tree1[i] << ' ';
            // cout << endl;
            scanf("%d", &A);
            query(A);
        }
    }
    return 0;
}