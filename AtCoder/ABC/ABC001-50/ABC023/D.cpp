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
//#define INF 1000000007
#define ARRAY_MAX 100005
const ll INF = 1e17;

ll n;
bool check(ll middle,vector<ll>& t,vector<ll>& s,vector<ll>& h){

    REP(i,n){
        if(middle - h[i] < 0){
            return false;
        }
        t[i] = (middle - h[i])/s[i];
    }
    VSORT(t);

    REP(i,n){
        if(i > t[i]){
            return false;
        }
    }
    return true;
}


int main(){

    cin >> n;
    vector<ll> h(n),s(n),t(n,0);
    REP(i,n){
        cin >> h[i] >> s[i];
    }
    ll left = 0;
    ll right = INF;//高さ最大
    while(right-left > 1){
        ll middle = (left+right)/2;//高さの上限
        if(check(middle,t,s,h)){
            right = middle;
        }else{
            left = middle;
        }
    }
    cout << right << endl;


    return 0;
}
