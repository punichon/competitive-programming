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

    int n,m,Q;
    cin >> n >> m >> Q;
   

    int city[n+1][n+1];
    for(int i = 0;i < n+1;i++){
        for(int j = 0;j < n+1;j++){
            city[i][j] = 0;
        }
    }


    int left,right;

    for(int i = 0;i < m;i++){//L
        cin >> left >> right;
        city[left][right]++;
    }

    REP(i,n+1){
        REP(j,n){
            city[i][j+1] += city[i][j]; 
        }
    }

    int p,q;

    for(int i = 0;i < Q;i++){

        int ans = 0;
        cin >> p >> q;
        for(int j = p;j < q+1;j++){

            ans+= city[j][q]-city[j][p-1];
        }

        cout << ans << endl;
    }


   
    return 0;
}
