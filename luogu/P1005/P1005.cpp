#include <iostream>
#include <cstdio>
using namespace std;
const int MAXLEN = 85;
typedef long long ll;
int n,m;
const ll P = 1e18;
struct int128{
    ll hig;
    ll low;
} mat[MAXLEN][MAXLEN], ans({0, 0}), dp[MAXLEN][MAXLEN];
int128 operator + (int128 a, int128 b){
    int128 c({0, 0});
    ll cp = (a.low + b.low) / P;
    c.low = (a.low + b.low) % P;
    c.hig = a.hig + b.hig + cp;
    return c;
}
int128 max(int128 a, int128 b){
    if(a.hig < b.hig)
        return b;
    else if(a.hig > b.hig)
        return a;
    else
        return (a.low < b.low) ? b : a;
}
int128 operator * (int128 a, ll b){     // 这里默认a.low * b 不会溢出
    int128 c({0, 0});
    ll cp = (a.low * b) / P;
    c.low = (a.low * b) % P;
    c.hig = a.hig * b + cp;
    return c;
}
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            scanf("%lld", &mat[i][j].low);
            mat[i][j].hig = 0;
        }
    for (int i = 1; i <= n; i++){
        // 分别计算每一行
        for (int l = 1; l <= m; l++){
            // 枚举区间长度
            for (int j = 1; j <= m; j++){
                // 枚举起点
                int r = j + l - 1;
                if(r > m)
                    break;
                if(l==1)
                    dp[j][j] = mat[i][j] * 2;
                else{
                    // cout << (dp[j][r - 1] + mat[i][r]).low << '|' << (dp[j + 1][r] + mat[i][j]).low << endl;
                    dp[j][r] = max((dp[j][r - 1] + mat[i][r]), (dp[j + 1][r] + mat[i][j])) * 2;
                    // cout << dp[j][r].low << endl;
                }
            }
        }
        ans = ans + dp[1][m];
        // cout << dp[1][m].low << endl;
    }
    if(ans.hig !=0){
        cout << ans.hig;
        printf("%018lld", ans.low);
    }else{
        cout << ans.low;
    }
}