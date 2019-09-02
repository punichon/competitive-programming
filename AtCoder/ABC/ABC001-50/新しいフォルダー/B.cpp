#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>

#define REP(n) for(int i = 0;i < n;i++)
#define LLREP(n) for(long long int  i = 0;i < n;i++)
typedef long long int ll;
using namespace std;
#define MAX_A 1000000

int main(){

    ll n,m;
    cin >> n;
    vector<ll> t(MAX_A);
    vector<ll> sum(MAX_A,0);
    REP(n){
        cin >> t[i];
        sum[i] = t[i];
    }

    for(int i = 0;i < n;i++){
        sum[i+1]+=sum[i];
    }


    /*REP(n){
        cout << sum[i] << endl;
    }*/

    //cout << endl;
    cin >> m;
    ll ans = 0;
    ll p,x;
    REP(m){
        cin >> p >> x;
        if(t[p-1] > x){
            ans = sum[n]-(t[p-1]-x);
            cout << ans << endl;
        }else if(t[p-1] < x){
            ans = sum[n]+(x-t[p-1]);
            cout << ans << endl;
        }else{
            cout << sum[n] << endl;
        }
    }






    return 0;
}
