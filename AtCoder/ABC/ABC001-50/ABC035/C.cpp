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

    int n,q;
    cin >> n >> q;
    vector<int> a(ARRAY_MAX,0);
    int l,r;
    REP(i,q){
        cin >> l >> r;
        a[l-1]++;
        a[r]--;
    }
    REP(i,n){
        a[i+1] += a[i];
    }

    REP(i,n){
        if(a[i]%2 == 0){
            cout << "0";
        }else{
            cout << "1";
        }
    }
    cout << endl;





    return 0;
}
