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
#define ARRAY_MAX 10005

const int INF = 1e9+7;

int num[10] = {0,2,5,5,4,5,6,3,7,6};
bool use[10];
int dp[ARRAY_MAX];//dp[i]:i本使って条件を満たす整数を作る時の最大の桁数

int main(){

    ll n,m;
    cin >> n >> m;
    vector<ll> a(m);
    for(int i = 0;i < m;i++){
        cin >> a[i];
        use[a[i]] = true;
    }
    memset(dp,-INF,sizeof(dp));
    dp[0] = 0;
    for(int i = 0;i < m;i++){
        for(int j = 0;j <= n;j++){
            if(j >= num[a[i]]){
                dp[j] = max(dp[j],dp[j-num[a[i]]]+1);//a[i]を使う場合と使わない場合
            }
        }
    }
    int tmp = dp[n];
    for(int i = 1;i <= tmp;i++){//1桁目からtmp桁目まで（条件を満たす整数の最大桁数がtmp桁のため）
        for(int j = 9;j >= 1;j--){//大きい順に調べるほうが最適なので
            if(use[j] == true && num[j] <= n && dp[n-num[j]] == dp[n]-1){
                cout << j;
                n -= num[j];
                break;
            }
        }
    }
    cout << endl;




    return 0;
}
