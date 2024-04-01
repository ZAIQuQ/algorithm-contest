#include <iostream>
using namespace std;
const int N = 25;
typedef long long ll;
ll fibo[N][2];
ll sum[N][2];
int a,b, n, m, x;
int main()
{
    cin >> a >> n >> m >> x;
    fibo[1][0] = 1;
    fibo[1][1] = 0;
    fibo[2][0] = 0;
    fibo[2][1] = 1;
    sum[2][0] = 1;
    sum[2][1] = 0;
    for (int i = 3; i <= n; i++){
        fibo[i][0] = fibo[i - 1][0] + fibo[i - 2][0];
        fibo[i][1] = fibo[i - 1][1] + fibo[i - 2][1];
        sum[i][0] = sum[i-1][0] +  fibo[i - 2][0];
        sum[i][1] = sum[i-1][1] +  fibo[i - 2][1];
        // cout << fibo[i][0] << '|' << fibo[i][1] << endl;
    }
    b = (m - sum[n - 1][0] * a) / sum[n - 1][1];
    cout << sum[x][0] * a + sum[x][1] * b << endl;
    return 0;
}