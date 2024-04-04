#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,sum[100010],q[100010],h[100010];  // 疲劳前缀和 前i个最大值 后i个最大值 
struct node{
    int s; // 距离
    int a; // 疲劳 
}v[100010];
bool cmp(node x,node y){return x.a>y.a;}
int main()
{	scanf("%d",&n);
    // 读数据
    for(int i=1;i<=n;i++)
        scanf("%d",&v[i].s); 
    for(int i=1;i<=n;i++)
        scanf("%d",&v[i].a);
    sort(v+1,v+1+n,cmp);//按疲劳排序 
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+v[i].a; 
    for(int i=1;i<=n;i++)
        q[i]=max(q[i-1],2*v[i].s);//前i个最大值
    for(int i=n;i>=1;i--)
        h[i]=max(h[i+1],2*v[i].s+v[i].a);//后i个最大值
    for(int i=1;i<=n;i++)
        printf("%d\n",max(sum[i]+q[i],sum[i-1]+h[i]));
    return 0;
}



// #include<iostream>
// #include<algorithm>
// using namespace std;
// typedef long long ll;
// int n;
// const int N = 1e5 + 100;
// struct node{
//     int x;
//     int w;
//     int idx;
//     int a;
// } arr[N];
// ll ans = 0;
// int curx = 0;
// int maxx = 0;
// bool mycmp1(node a, node b){
//     return a.a > b.a;
// }
// int main(){
//     cin >> n;
//     for (int i = 1; i <= n; i++){
//         scanf("%d", &arr[i].x);
//     }
//     maxx = arr[n].x;
//     for (int i = 1; i <= n; i++){
//         scanf("%d", &arr[i].w);
//         arr[i].idx = i;
//         arr[i].a = 2 * arr[i].x + arr[i].w;
//     }
//     // 先把第一个确定
//     sort(arr + 1, arr + 1 + n, mycmp1);
//     ans += arr[1].a;
//     curx = arr[1].x;
//     cout << ans << endl;
//     for (int i = 2; i <= n; i++){
//         if(arr[i].x <= curx){
//             arr[i].a -= arr[i].x * 2;
//         }else{
//             arr[i].a -= curx * 2;
//         }
//     }
//     for (int i = 2; i <= n; i++)
//     {
//         sort(arr + i, arr + 1 + n, mycmp1);
//         ans += arr[i].a;
//         cout << ans << endl;
//         // 如果距离拉长，更新其它数据
//         if(curx < arr[i].x){
//             register int delta = arr[i].x - curx;
//             for (int j = i+1; j <= n; j++){
//                 if( curx < arr[j].x && arr[j].x <= arr[i].x)
//                     arr[j].a -= (arr[j].x - curx) * 2;
//                 else if(arr[j].x > arr[i].x)
//                     arr[j].a -= delta * 2;
//             }
//             curx = arr[i].x;
//         }
        
//     }
//     return 0;
// }