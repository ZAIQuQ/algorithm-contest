#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int N = 2e5 + 50;
int n;
int V[N], C[N], F[N];
int bigson[N], sonnum[N];
int cnt_cnt[N], cnt[N];
vector<int> E[N];
int ans = 0;
void dfs0(int v){
    sonnum[v] = 1;                          // 根节点计数
    for(int e : E[v]){
        dfs0(e);                            // 统计各子树节点数
        sonnum[v] += sonnum[e];
        if(sonnum[e] > sonnum[bigson[v]])   // 得到重儿子，如果没有默认为0
            bigson[v] = e;
    }
}
void ColorCnt(int v, int one){
    // 保存根节点颜色
    cnt_cnt[cnt[C[v]]]--;                   // 根节点颜色计数器变化，故对应数量的计数器减一
    cnt[C[v]] += one;                       // 根节点颜色计数器加一 / 减一
    cnt_cnt[cnt[C[v]]]++;                   // 根节点颜色数量的计数器加一
    for(int e : E[v])
        ColorCnt(e, one);                   // 轻子树第二次遍历已经不需要统计ans了，只用于维护Coler Cnt
}
void search(int v, bool save){
    for(int e : E[v]) 
        if(e != bigson[v])
            search(e, false);               // 先不保存地轻搜轻子树
    //  此时计数器仍为0
    if(bigson[v])
        search(bigson[v], true);            // 再有保存地重搜重子树
    //  保存根节点颜色
    cnt_cnt[cnt[C[v]]]--;                   // 根节点颜色计数器变化，故对应数量的计数器减一
    cnt[C[v]]++;                            // 根节点颜色计数器加一
    cnt_cnt[cnt[C[v]]]++;                   // 根节点颜色数量的计数器加一
    for(int e : E[v])
        if(e != bigson[v])
            ColorCnt(e, 1);                 // 保存计数器地dfs轻子树
    if(cnt[C[v]] * cnt_cnt[cnt[C[v]]] == sonnum[v])
        ans++;
    if(!save)
        ColorCnt(v, -1);                    // save为false，说明是对轻子树的第一次遍历，需要还原cnt
}
int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        scanf("%d %d", C + i, F + i);
        E[F[i]].push_back(i);
    }
    memset(bigson, 0, sizeof(bigson));
    sonnum[0] = 0;
    dfs0(1); // 计算子树节点个数和重儿子序号
    search(1, true);
    cout << ans << endl;
}