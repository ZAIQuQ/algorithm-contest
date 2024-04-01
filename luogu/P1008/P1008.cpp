#include <iostream>
#include <cstring>
using namespace std;
int num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int flag[10];
void test(int a,int b,int c){
    if(c > 999)
        return;
    int b_t[4];
    int c_t[4];
    b_t[1] = b / 100;
    b_t[3] = b % 100;
    b_t[2] = b_t[3] / 10;
    b_t[3] = b_t[3] % 10;
    int fl = 0;
    for (int i = 1; i <= 3; i++){
        if(b_t[i] == 0 || flag[b_t[i]]){
            fl = i;
            break;
        }else{
            flag[b_t[i]] = 1;
        }
    }
    if(fl){
        for (int i = 1; i < fl; i++)
            flag[b_t[i]] = 0;
        return;
    }else{
        c_t[1] = c / 100;
        c_t[3] = c % 100;
        c_t[2] = c_t[3] / 10;
        c_t[3] = c_t[3] % 10;
        int fl_ = 0;
        for (int i = 1; i <= 3; i++){
            if(c_t[i] == 0 || flag[c_t[i]]){
                fl_ = i;
                break;
            }else{
                flag[c_t[i]] = 1;
            }
        }
        if(fl_){
            for (int i = 1; i <= 3; i++)
                flag[b_t[i]] = 0;
            for (int i = 1; i < fl_; i++)
                flag[c_t[i]] = 0;
            return;
        }else{
            cout << a << " " << b << " " << c << endl;
            for (int i = 1; i <= 3; i++){
                flag[b_t[i]] = flag[c_t[i]] = 0;
            }
            return;
        }
    }
}
int main(){
    memset(flag, 0, sizeof flag);
    for (int i = 1; i <= 3;i++){
        flag[i] = 1;
        for (int j = 1; j <= 9; j++){
            if(flag[j]){
                continue;
            }else{
                flag[j] = 1;
                for (int k = 1; k <= 9; k++){
                    if(flag[k]){
                        continue;
                    }else{
                        int t = i * 100 + j * 10 + k;
                        flag[k] = 1;
                        test(t, t * 2, t * 3);
                        flag[k] = 0; // »ØËİ
                    }
                }
                flag[j] = 0; // »ØËİ
            }
        }
        flag[i] = 0;
    }
}