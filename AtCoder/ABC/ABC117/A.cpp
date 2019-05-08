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
using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
typedef pair<int, int> pii;
typedef long long int ll;
typedef pair<ll,ll> pll;
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
#define MOD 1000000007
#define ARRAY_MAX 100005

const int INF = 1e9+7;


int main(){

    double a,b;
    cin >> a >> b;
    printf("%.12f\n",a/b);

    return 0;
}
