#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long int ll;

int main(){

    int n;
    cin >> n;
    ll tmp1 = 0,tmp2 = 0;
    ll ans = 1000000000000000000LL;
    
    vector<ll> a(n);

    for(int i = 0;i < n;i++){
        cin >> a[i];
        tmp1+=a[i];
    }


    for(ll i = 0;i < n-1;i++){
        tmp2+=a[i];
        ans = min(ans,abs(tmp1-2*tmp2));
    }
    cout << ans << endl;        

}
