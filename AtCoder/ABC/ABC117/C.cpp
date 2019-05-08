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

const int INF = 1e9+7;


int main(){

    ll n,m;
    cin >> n >> m;
    vector<ll> a(m);
    for(int i = 0;i < m;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());

    priority_queue<ll> que;

    for(int i = 0;i < m-1;i++){
        que.push(a[i+1]-a[i]);
    }

    ll ans = 0;
    ll coma = n-1;

    while(!que.empty()){

        //cout << que.top() << endl;
        if(coma > 0){
            coma--;
            que.pop();
        }else{
            ans += que.top();
            que.pop();
        }
        //cout << coma << " " << ans << endl;
    }

    cout << ans << endl;




    return 0;
}
