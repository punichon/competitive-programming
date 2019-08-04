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
#include<queue>

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
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
//#define INF 1000000007
#define MOD 1000000007
#define MAX_N 105
#define MAX_V 1005
const ll INF = LLONG_MAX/2;



ll c[51][51];

void combination(int n){
 
    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= i;j++){
            if(j == 0 || i == j){
                /*nC0 = 1、nCn = 1*/
                c[i][j] = 1LL;
            }else{
                c[i][j] = c[i-1][j-1] + c[i-1][j];
            }
        }
    }
}

int main(){

    ll n,a,b;
    cin >> n >> a >> b;
    vector<ll> arr(n);
    vector<ll> vec;
    REP(i,n){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end(),greater<ll>());
    combination(n);

    ll sum = 0;
    REP(i,a){
        sum += arr[i];
    }

    ll N = 0,R = 0;
    for(int i = 0;i < n;i++){
        if(arr[i] == arr[a-1]){
            N++;
            if(i < a){
                R++;
            }
        }
    }

    double ave = sum/double(a);
    ll ans = 0;
    if(R == a){

        for(ll i = a;i <= b;i++){
            ans += c[N][i];
        }
    }else{
        ans += c[N][R];
    }
    printf("%.8f\n%lld\n",ave,ans);


    return 0;
}
