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

    ll n,k;
    cin >> n >> k;

    vector<pll> a(n);
    vector<bool> used(ARRAY_MAX,false);

    for(int i = 0;i < n;i++){
        cin >> a[i].second >> a[i].first;
    }

    sort(a.begin(),a.end(),greater<pll>());

    priority_queue<ll,vector<ll>,greater<ll> > que;

    ll sum = 0,ans = 0,kind = 0;

    for(int i = 0;i < k;i++){

        sum += a[i].first;
        if(used[a[i].second] == false){//まだ使われていない種類
            kind++;
            used[a[i].second] = true;
        }else{
            que.push(a[i].first);
        }
    }

    ans = sum + kind*kind;

    for(int i = k;i < n;i++){

        if(que.empty()){
            break;
        }
        if(used[a[i].second] == false){

            sum -= que.top();
            que.pop();
            kind++;
            sum += a[i].first;
            used[a[i].second] = true;
            ans = max(ans,sum + kind*kind);
        }
    }

    cout << ans << endl;


    return 0;
}
