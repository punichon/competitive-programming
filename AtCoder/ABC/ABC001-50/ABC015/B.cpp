#include<iostream>
using namespace std;

int main(){

    int n,tmp,sum = 0,num;
    cin >> n;
    num = n;
    for(int i = 0;i < n;i++){
        cin >> tmp;
        if(tmp == 0){
            num--;
        }
        sum += tmp;
    }
    double ave = sum / (double)num;
    
    int ans = (int)(ave + 0.9);
    //cout << sum << endl;
    //cout << ave << endl;
    cout << ans << endl;

    return 0;
}
