#include<iostream>
using namespace std;

int main(){

    long long int X,t;

    cin >> X >> t;

    long long int ans = X-t;
    if(ans < 0){
        ans = 0;
    }

    cout << ans << endl;
    return 0;

}
