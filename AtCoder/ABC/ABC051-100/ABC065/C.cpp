#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<deque>
using namespace std;
typedef long long int ll;

#define MAX_A 10000000
const ll MOD = 1000000007;


int main(){

    int n,m;
    ll ans = 0;
    cin  >> n >> m;
    if(abs(n-m) > 1){
        cout << "0" << endl;
        return 0;
    }

    vector<ll> a(MAX_A,0);
    a[0] = 1;
    for(int i = 1;i <= max(n,m);i++){

        a[i] = a[i-1]*i%MOD;
    }
    
    if(abs(n-m)==1){
        cout << a[n]*a[m]%MOD << endl;
    }else{
        cout << 2*a[n]*a[m]%MOD << endl;
    }
 

    return 0;

}
