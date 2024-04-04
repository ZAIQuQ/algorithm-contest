#include <bits/stdc++.h>
using namespace std;
long long n,a[100010],q[100010],w[100010][2],ans=0;
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
        q[i]=q[i-1]^a[i];
    for(int i=0;i<=n;i++)
        for(int j=31;j>=0;j--)
	        w[j][(q[i]>>j)&1]++;        // 0,1个数记录器
	for(int i=0;i<=31;i++)
	    ans+=w[i][0]*w[i][1]*(1<<i);    // 求和
	printf("%lld",ans);
	return 0;
}