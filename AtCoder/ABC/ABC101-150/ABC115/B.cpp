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
#include<climits>

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

#define ARRAY_MAX 200005

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    int maxi = -1;
    REP(i,n){
        cin >> a[i];
        maxi = max(maxi,a[i]);
    }
    bool used = false;
    int ans = 0;
    REP(i,n){
        if(maxi == a[i] && used == false){
            ans += a[i]/2;
            used = true;
        }else{
            ans += a[i];
        }
    }
    cout << ans << endl;




    return 0;
}
