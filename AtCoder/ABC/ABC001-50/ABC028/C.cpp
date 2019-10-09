#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include <numeric>
#include<queue>
#include<climits>


#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n)
#define VSORT(v) sort(v.begin(), v.end())
#define llong long long
#define pb(a) push_back(a)
//#define INF LLONG_MAX / 2;
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef long long int ll;
typedef pair<ll,int> LL_IP;

const ll INF = LLONG_MAX;

#define ARRAY_MAX 100005


int main(){

    int a,b,c,d,e;
    cin >> a >> b >> c >> d >> e;
    cout << max(a+d+e,b+c+e) << endl;





    return 0;
}
