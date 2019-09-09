#include<iostream>
using namespace std;

int main(){

    int n,k,x,y,ans;
    cin >> n >> k >> x >> y;
    if (k < n){
        ans = k*x + (n-k)*y;
    }else{
        ans = n*x;
    }
        cout << ans << endl;

    return 0;
}
