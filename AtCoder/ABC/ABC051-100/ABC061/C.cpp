#include<iostream>
#include<vector>
#include<algorithm>

#define REP(n) for(int i = 0;i < n;i++)
typedef long long int ll;
using namespace std;
#define MAX_A 100005

int main(){

    vector<ll> num(MAX_A,0);
    ll n,k,a,b;
    cin >> n >> k;
    //cout << n << k << endl;
    REP(n){
        cin >> a >> b;
        //cout << a << b << endl;
        num[a] += b;
        //cout << num[a] << endl;
    }
    /*REP(n+1){
        cout << num[i];
    }
    cout << endl;*/

    for(ll i = 1;i < MAX_A;i++){
        //cout << num[i];
        //cout << k << endl;
        if(k <= num[i]){
            cout << i << endl;
            return 0;
        }
        k-=num[i];
       
    }

    
     
    return 0;
}
