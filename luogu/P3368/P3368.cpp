#include<iostream>
#include<cstring>
using namespace std;
inline int lowbit(int x) { return x & -x; }
int n, m;
const int N = 5e5 + 10;
int a[N];
int b[N];
int tree[N];
void add(int x, int k){
    for (int i = x; i <= n ; i+= lowbit(i))
        tree[i] += k;
}
void partAdd(int x,int y,int k){
    // 转换成两处单点修改
    add(x, k);
    add(y + 1, -k);
}

void query(int x){
    // 对b[1~x]求和等价于求a[x]
    int ans = 0;
    for (int i = x; i >= 1; i -= lowbit(i))
        ans += tree[i];
    cout << ans << endl;
}
int main(){
    a[0] = 0;
    memset(tree, 0, sizeof tree);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        scanf("%d", a + i);
        b[i] = a[i] - a[i - 1];
        for (int j = i; j <= n; j+=lowbit(j)){
            tree[j] += b[i];
        }
    }
        int op, x, y, k;
    while(m--){
        cin >> op;
        if(op == 1){
            cin >> x >> y >> k;
            partAdd(x, y, k);
        }else{
            cin >> x;
            query(x);
        }
    }
    return 0;
}