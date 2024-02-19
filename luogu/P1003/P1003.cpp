#include <iostream>
#include <cstring>
using namespace std;
const int MAXLEN = 1e4 + 5;
int n,idx=0;
typedef struct node{
    int a;
    int b;
    int c;
    int d;
} node;
node F[MAXLEN];
int main()
{
    cin >> n;
    while(n--)
    {
        idx++;
        scanf("%d %d %d %d", &F[idx].a, &F[idx].b, &F[idx].c, &F[idx].d);
    }
    int a, b;
    cin >> a >> b;
    for (int i = idx; i >= 1; i--)
    {
        if( ( F[i].a <= a && a < F[i].a+F[i].c ) && ( F[i].b <= b && b < F[i].b+F[i].d ) )
        {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}