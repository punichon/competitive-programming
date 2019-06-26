#include<iostream>
#include<cmath>
using namespace std;

int main(){

    long long int x,y;
    cin >> x >> y;
    int ans = 0;
    while(x <= y){
        ans++;
        x*=2;
    }

    cout << ans << endl;

    return 0;
}
