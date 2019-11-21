#include<iostream>
using namespace std;

int main(){

    int a,b,ans;
    cin >> a >> b;
    if(a % b != 0){
        ans = (a / b + 1)*b - a;
    }else{
        ans = 0;
    }
    cout << ans << endl;


    return 0;
}
