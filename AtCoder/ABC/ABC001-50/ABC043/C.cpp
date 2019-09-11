#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<map>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 999999999
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef long long int ll;

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    int mini = INF;
    int maxi = -INF;
    REP(i,n){
        cin >> a[i];
        mini = min(mini,a[i]);
        maxi = max(maxi,a[i]);
    }

    int ans = INF;
    FOR(i,mini,maxi+1){
        int tmp = 0;
        REP(j,n){

            tmp += pow(a[j]-i,2);

        }
        ans = min(ans,tmp);
        //cout << i << ans << endl;
    }
    cout << ans << endl;

    return 0;
}
