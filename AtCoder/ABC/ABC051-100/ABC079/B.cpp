#include<iostream>
#include<vector>
using namespace std;

typedef long long int ll;

int main(){

    ll n;
    cin >> n;
    vector<ll> a(n+10);
    a[0] = 2;
    a[1] = 1;
    for(int i = 2;i <= n;i++){
        a[i] = a[i-1]+a[i-2];
    }
    cout << a[n] << endl;
    return 0;
}
