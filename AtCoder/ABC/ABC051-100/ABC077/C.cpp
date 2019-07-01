#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;

typedef long long int ll;

int main(){

    ll n,ans=0;
    cin >> n;

    /*vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c(n);*/

    ll a[n];
    ll b[n];
    ll c[n];
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < n;i++){
        cin >> b[i];
    }
    for(int i = 0;i < n;i++){
        cin >> c[i];
    }

    /*sort(a.begin(),a.end());
    sort(c.begin(),c.end());*/

    sort(a,a+n);
    sort(c,c+n);

    for(int j = 0;j < n;j++){
        /*int i = a.lower_bound(b[j])-1;
        int k = n-c.upper_bound(b[j]);*/
        ll i = lower_bound(a,a+n,b[j])-a;
        ll k = n-(upper_bound(c,c+n,b[j])-c);
        //cout << i << " " << k << endl;

        ans = ans+i*k;
        //cout << ans << endl;
    }
    cout << ans << endl;

    return 0;
}
