#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<climits>
#include<set>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
typedef pair<ll,ll> pll;
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
#define MOD 1000000007
#define ARRAY_MAX 100005

const ll INF = 1e17+7;


int main(){

    ll n,m;
    cin >> n >> m;
    vector<ll> x(n),y(m);
    ll mini = INF;
    for(int i = 0;i < n;i++){
        cin >> x[i];
        mini = min(mini,x[i]);
    }
    if(mini < 0){
        for(int i = 0;i < n;i++){
            x[i] -= mini;
        }
    }
    mini = INF;
    for(int i = 0;i < m;i++){
        cin >> y[i];
        mini = min(mini,y[i]);
    }
    if(mini < 0){
        for(int i = 0;i < m;i++){
            y[i] -= mini;
        }
    }
    vector<ll> xs(n+1,0),ys(m+1,0);
    
    //累積和
    for(int i = 1;i <= n;i++){
        xs[i] = xs[i-1] + x[i-1];
    }
    for(int i = 1;i <= m;i++){
        ys[i] = ys[i-1] + y[i-1];
    }

    ll x_cnt = 0,y_cnt = 0;//縦、横の長さの総和

    for(int i = 1;i <= n-1;i++){
        x_cnt += (xs[n]-xs[n-i]) - xs[i];
        x_cnt %= MOD;
    }
    
    for(int i = 1;i <= m-1;i++){
        y_cnt += (ys[m]-ys[m-i]) - ys[i];
        y_cnt %= MOD;
    }

    cout << (x_cnt * y_cnt)%MOD << endl;







    return 0;
}
