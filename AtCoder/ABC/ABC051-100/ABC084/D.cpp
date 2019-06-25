#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 1000000000
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef long long int ll;

#define ARRAY_MAX 100005
#define MOD 1000000007


/*nまでの素数を列挙して配列に保持*/
vector<ll> Eratosthenes(ll n,vector<ll>& arr){
    
    for(ll i = 0; i < n;i++){
        arr[i] = 1;
    }
    arr[0] = arr[1] = 0;
    for(ll i = 2; i < sqrt(n); i++){
        if(arr[i]){
            for(ll j = 0; i * (j + 2) < n; j++){
                arr[i *(j + 2)] = 0;
            }
        }
    }
    return arr;
}


int main(){

    ll q;
    cin >> q;
    vector<ll> a(ARRAY_MAX,0),b(ARRAY_MAX,0);
    a = Eratosthenes(ARRAY_MAX,a);
   
    for(int i = 0;i <= 100000;i++){
        if(a[i] && a[(i+1)/2]){
            b[i] = 1;
        }
    }
      
    for(int i = 0;i <= 100000;i++){
        b[i+1]+=b[i];
    }

    ll l,r;
    REP(i,q){
        cin >> l >> r;
        cout << b[r] - b[l-1] << endl;
    }

    return 0;
}
