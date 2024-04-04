#include <iostream>
#include <cstring>
using namespace std;
const int N = 5e5 + 50;
int n, m, op, x, y;
int arr[N];
inline int lowbit(int x) { return x & (-x); }
struct TA{
    int tree[N];
    void init(int len){
        memset(tree, 0, sizeof(tree));
        for (int i = 1; i <= len; i++)
            for (int j = i - lowbit(i) + 1; j <= i; j++)
                tree[i] += arr[j];
    }
    void add(int x, int y){
        arr[x] += y;
        for (int i = x; i <= n; i+=lowbit(i))
            tree[i] += y;
    }
    int sum(int x){ 
        // ¼ÆËã [1,x]µÄºÍ
        int ans = 0;
        for (int i = x; i > 0; i-=lowbit(i))
            ans += tree[i];
        return ans;
    }
} treearr;
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        scanf("%d", arr + i);
    treearr.init(n);
    while(m--){
        cin >> op >> x >> y;
        if(op == 1){
            treearr.add(x, y);
        }else{
            cout << treearr.sum(y) - treearr.sum(x - 1) << endl;
        }
    }
    return 0;
}