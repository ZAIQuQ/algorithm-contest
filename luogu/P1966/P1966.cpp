#include <iostream>
#include <algorithm>
using namespace std;
inline int lowbit(int x) { return x & -x; }
const int N = 1e5 + 10;
const int Q = 1e8 - 3;
typedef long long ll;
struct node{
    int val;
    int idx;
} a[N], b[N];
int rankA[N];
int rankB[N];
int n;
ll tree[N];

bool mycmp(node a, node b){
    if(a.val == b.val)
        return a.idx < b.idx;
    else
        return a.val < b.val;
}
void add(int x){
    for (int i = x; i <= n; i+=lowbit(i))
        tree[i] += 1;
}
ll query(int x){
    ll sum = 0;
    for (int i = x; i >= 1; i-=lowbit(i))
        sum += tree[i];
    return sum;
}
int main(){
    ll ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i].val);
        a[i].idx = i;
    }
    for (int i = 1; i <= n; i++){
        scanf("%d", &b[i].val);
        b[i].idx = i;
    }
    sort(a + 1, a + 1 + n, mycmp);
    sort(b + 1, b + 1 + n, mycmp);
    for (int i = 1; i <= n; i++){
        rankA[a[i].idx] = i;
        rankB[b[i].idx] = i;
    }
    for (ll i = 1; i <= n; i++){
        add(b[rankA[i]].idx);
        ans += i - query(b[rankA[i]].idx);
        ans =  (ans + Q) % Q;
    }
    cout << ans << endl;
    return 0;
}