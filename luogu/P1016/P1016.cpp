#include <iostream>
#include<cstdio>
#include<queue> 
// ֻѡ�����ȵ�ǰ�ͼ�С�ĵ�һ������վ
// ���û�бȵ�ǰ�ͼ�С�ļ���վ��ֱ��ȥ�յ�
// ���ȥ��Ŀ�귢�������Ͳ����ˣ�ѡ���䷶Χ����С�ļ���վ
using namespace std;
double ans = 0;
double alldis, V, DisPerL, p0;
int n;
double station[7];
double price[7];
bool mycmp(double a, double b){
    return a < b;
}
int main(){
    cin >> alldis >> V >> DisPerL >> p0 >> n;
    register double fulldis = V * DisPerL;             // ��Զ����
    register int idx = 0;                              // ��վ����
    register double  curgas = 0;
    for (int i = 1; i <= n;i++){
        cin >> station[i] >> price[i];
    }
    price[0] = p0;  // ����ͼ�
    station[0] = 0;
    bool success = false;
    while(!success){
        int t = idx+1;
        while( t <= n && price[t] >= price[idx])        // ���ұȵ�ǰ�ͼ�С����վ
            t++;
        if(t > n){
            // ��ǰ��վ�ͼ���С�����յ�ΪĿ��
            if(fulldis < alldis - station[idx]){
                // cout << idx << endl; �˳���ʱ��idxΪ7
                // �������յ�              
                // ������Ե������վ��Χ
                t = idx + 1;
                while(t <= n && ( fulldis >= station[t] - station[idx] ) )
                    t++;
                --t;
                if(t == idx){
                    // �������κ���վ
                    //cout << idx << '!' <<endl;
                    break;
                }else{
                    // �ҵ��۸������վ
                    double cheaper = 999999;
                    int min_idx;
                    int j = idx + 1;
                    for ( ; j <= t; j++){
                        if(price[j] < cheaper){
                            min_idx = j;
                            cheaper = price[j];
                        }
                    }
                    // ������,��idxǰ��j��վ
                    ans += price[idx] * (V - curgas);
                    curgas = V - ((station[min_idx] - station[idx]) / DisPerL);
                    // cout << idx << '|' << j << endl;
                    idx = min_idx;
                    continue;
                } 
            }else{
                // ������idxǰ���յ�
                ans += ((alldis - station[idx]) / DisPerL - curgas) * price[idx];
                //cout << ans << endl;
                success = true;
                break;
            }
        }else{
            // �и�С����վ���Ը���վΪĿ��
            if(fulldis < station[t] - station[idx]){
                // �����˸���վ
                // ������Ե������վ��Χ
                t = idx + 1;
                while(t <= n && ( fulldis >= station[t] - station[idx] ) )
                    t++;
                --t;
                if(t == idx){
                    // �������κ���վ
                    //cout << idx  << '?' << endl;
                    break;
                }else{
                    // �ҵ��۸������վ
                    double cheaper = 999999;
                    int min_idx;
                    int j = idx + 1;
                    for (; j <= t; j++){
                        if(price[j] < cheaper){
                            min_idx = j;
                            cheaper = price[j];
                        }
                    }
                    // �����ͣ���idxǰ��min_idxվ
                    ans += price[idx] * (V - curgas);
                    curgas = V - (station[min_idx] - station[idx]) / DisPerL; // �Ͳ�û������
                    idx = min_idx;
                    continue;
                }
            }else{
                // ��idx����ǰ��tվ
                ans += ((station[t] - station[idx]) / DisPerL - curgas) * price[idx];
                // cout << t << '|' << idx << '|' << curgas << endl;
                // cout << ans << endl;
                curgas = 0;
                idx = t;
                continue;
            }
        }
    }
    if(success){
        printf("%.2lf", ans);
    }else{
        cout << "No Solution" << endl;
    }
    return 0;
}
