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
    sonnum[v] = 1;                          // ���ڵ����
    for(int e : E[v]){
        dfs0(e);                            // ͳ�Ƹ������ڵ���
        sonnum[v] += sonnum[e];
        if(sonnum[e] > sonnum[bigson[v]])   // �õ��ض��ӣ����û��Ĭ��Ϊ0
            bigson[v] = e;
    }
}
void ColorCnt(int v, int one){
    // ������ڵ���ɫ
    cnt_cnt[cnt[C[v]]]--;                   // ���ڵ���ɫ�������仯���ʶ�Ӧ�����ļ�������һ
    cnt[C[v]] += one;                       // ���ڵ���ɫ��������һ / ��һ
    cnt_cnt[cnt[C[v]]]++;                   // ���ڵ���ɫ�����ļ�������һ
    for(int e : E[v])
        ColorCnt(e, one);                   // �������ڶ��α����Ѿ�����Ҫͳ��ans�ˣ�ֻ����ά��Coler Cnt
}
void search(int v, bool save){
    for(int e : E[v]) 
        if(e != bigson[v])
            search(e, false);               // �Ȳ����������������
    //  ��ʱ��������Ϊ0
    if(bigson[v])
        search(bigson[v], true);            // ���б��������������
    //  ������ڵ���ɫ
    cnt_cnt[cnt[C[v]]]--;                   // ���ڵ���ɫ�������仯���ʶ�Ӧ�����ļ�������һ
    cnt[C[v]]++;                            // ���ڵ���ɫ��������һ
    cnt_cnt[cnt[C[v]]]++;                   // ���ڵ���ɫ�����ļ�������һ
    for(int e : E[v])
        if(e != bigson[v])
            ColorCnt(e, 1);                 // �����������dfs������
    if(cnt[C[v]] * cnt_cnt[cnt[C[v]]] == sonnum[v])
        ans++;
    if(!save)
        ColorCnt(v, -1);                    // saveΪfalse��˵���Ƕ��������ĵ�һ�α�������Ҫ��ԭcnt
}
int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        scanf("%d %d", C + i, F + i);
        E[F[i]].push_back(i);
    }
    memset(bigson, 0, sizeof(bigson));
    sonnum[0] = 0;
    dfs0(1); // ���������ڵ�������ض������
    search(1, true);
    cout << ans << endl;
}