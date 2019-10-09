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
#include<set>
#include<climits>
#include<cstdio>
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
#define INF 1000000007

#define ARRAY_MAX 10005


int main(){

    ll n,k;
    cin >> n >> k;

    ll small = n-k;//kより小さい数字の個数
    ll large = k-1;//kより大きい数字の個数

    ll ans = 0;

    ans += 6*small*large;
    ans++;//全てkのケース

    ans += 3*(small+large);//kが2回
    double r = ans/double(n*n*n);
    printf("%.20f\n",r);



    return 0;
}
