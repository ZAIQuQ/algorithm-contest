#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int n;
inline int lowbit(int x) { return x & -x; }
const int N = 5e5 + 50;
struct node{
    int val;
    int idx;
} arr[N];
int ranks[N];
ll tree[N];
bool mycmp(node a, node b){
    // 重复数字，快排会乱序？
    // return a.val < b.val;
    if (a.val == b.val)
        return a.idx < b.idx;
    else
        return a.val < b.val;
}
void add(int x, ll k){
    for (int i = x; i <= n; i+=lowbit(i)){
        tree[i] += k;
    }
}
ll query(int x){
    ll sum = 0;
    for (int i = x; i >= 1; i-=lowbit(i)){
        sum += tree[i];
    }
    return sum;
}
int main(){
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++){
        scanf("%d", &arr[i].val);
        arr[i].idx = i;
    }
    sort(arr + 1, arr + 1 + n, mycmp);
    for (int i = 1; i <= n; i++){
        ranks[arr[i].idx] = i;
    }
    for (ll i = 1; i <= n; i++){
        add(ranks[i], 1);
        ans += i - query(ranks[i]); // 计算第i个数前面i-1个数中，有多少个比它大
    }
    cout << ans << endl;
    return 0;
}