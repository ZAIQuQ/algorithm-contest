#include <iostream>
using namespace std;
char box[20] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
int n, m;
void transfer(int n, int m){
    if(n == 0)
        return;
    else if(n % m >= 0){
        transfer(n/m, m);
        cout << box[n % m];
    }else{
        transfer(n/m+1, m);
        cout << box[n % m - m];
    }
}
int main(){
    cin >> n >> m;
    cout << n << '=';
    transfer(n, m);
    cout << "(base" << m << ")";
    return 0;
}