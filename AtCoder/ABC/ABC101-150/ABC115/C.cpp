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
#include<climits>
 
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;
typedef pair<ll,ll> LLP;
#define INF 10000000000007
 
#define ARRAY_MAX 100005
 
int main(){
 
    ll n,k;
    cin >> n >> k;
    vector<ll> a(ARRAY_MAX);
    REP(i,n){
        cin >> a[i];
    }
    sort(a.begin(),a.begin()+n);
    
    ll mini = INF;
    for(int i = 0;i < n-k+1;i++){
        mini = min(mini,a[i+k-1]-a[i]);
    }
    cout << mini << endl;
 
 
 
 
    return 0;
}
