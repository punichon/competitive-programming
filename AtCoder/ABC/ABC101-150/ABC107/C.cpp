#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 1000000000
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;

typedef long long int ll;
typedef pair<int,int> pp;


int main(){


    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    REP(i,n){
        cin >> a[i];
    }

    int ans = INF;

    for(int i = 0;i < n-k+1;i++){

        int tmp1 = abs(a[i]) + abs(a[i+k-1]-a[i]);
        int tmp2 = abs(a[i+k-1]) + abs(a[i+k-1]-a[i]);
        int tmp3 = min(tmp1,tmp2);
        ans = min(ans,tmp3);

    }
    cout << ans << endl;

    return 0;
}
