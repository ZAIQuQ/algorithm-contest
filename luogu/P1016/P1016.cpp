#include <iostream>
#include<cstdio>
#include<queue> 
// 只选择后面比当前油价小的第一个加油站
// 如果没有比当前油价小的加油站，直接去终点
// 如果去往目标发现油箱油不够了，选油箱范围内最小的加油站
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
    register double fulldis = V * DisPerL;             // 最远续航
    register int idx = 0;                              // 油站索引
    register double  curgas = 0;
    for (int i = 1; i <= n;i++){
        cin >> station[i] >> price[i];
    }
    price[0] = p0;  // 起点油价
    station[0] = 0;
    bool success = false;
    while(!success){
        int t = idx+1;
        while( t <= n && price[t] >= price[idx])        // 查找比当前油价小的油站
            t++;
        if(t > n){
            // 当前油站油价最小，以终点为目标
            if(fulldis < alldis - station[idx]){
                // cout << idx << endl; 退出的时候idx为7
                // 到不了终点              
                // 计算可以到达的油站范围
                t = idx + 1;
                while(t <= n && ( fulldis >= station[t] - station[idx] ) )
                    t++;
                --t;
                if(t == idx){
                    // 到不了任何油站
                    //cout << idx << '!' <<endl;
                    break;
                }else{
                    // 找到价格最低油站
                    double cheaper = 999999;
                    int min_idx;
                    int j = idx + 1;
                    for ( ; j <= t; j++){
                        if(price[j] < cheaper){
                            min_idx = j;
                            cheaper = price[j];
                        }
                    }
                    // 加满油,从idx前往j油站
                    ans += price[idx] * (V - curgas);
                    curgas = V - ((station[min_idx] - station[idx]) / DisPerL);
                    // cout << idx << '|' << j << endl;
                    idx = min_idx;
                    continue;
                } 
            }else{
                // 出发从idx前往终点
                ans += ((alldis - station[idx]) / DisPerL - curgas) * price[idx];
                //cout << ans << endl;
                success = true;
                break;
            }
        }else{
            // 有更小的油站，以该油站为目标
            if(fulldis < station[t] - station[idx]){
                // 到不了该油站
                // 计算可以到达的油站范围
                t = idx + 1;
                while(t <= n && ( fulldis >= station[t] - station[idx] ) )
                    t++;
                --t;
                if(t == idx){
                    // 到不了任何油站
                    //cout << idx  << '?' << endl;
                    break;
                }else{
                    // 找到价格最低油站
                    double cheaper = 999999;
                    int min_idx;
                    int j = idx + 1;
                    for (; j <= t; j++){
                        if(price[j] < cheaper){
                            min_idx = j;
                            cheaper = price[j];
                        }
                    }
                    // 加满油，从idx前往min_idx站
                    ans += price[idx] * (V - curgas);
                    curgas = V - (station[min_idx] - station[idx]) / DisPerL; // 油并没有用完
                    idx = min_idx;
                    continue;
                }
            }else{
                // 从idx出发前往t站
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
