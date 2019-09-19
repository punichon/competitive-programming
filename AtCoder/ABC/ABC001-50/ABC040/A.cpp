#include<iostream>
using namespace std;

int main(){

    int n,x,ans;
    cin >> n >> x;
    if(x <= n/2){
        ans = x-1;
    }else{
        ans = n-x;
    }

    cout << ans << endl;

    return 0;
}
