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
#define MOD 1000000007
#define ARRAY_MAX 1005
ll dx[4] = {1,0,0,-1};
ll dy[4] = {0,1,-1,0};

int main(){

    int n;
    cin >> n;
    vector<int> ax(n),ay(n),bx(n),by(n);
    double gax = 0,gay = 0,gbx = 0,gby = 0;
    REP(i,n){
        cin >> ax[i] >> ay[i];
        gax += ax[i];
        gay += ay[i];
    }
    REP(i,n){
        cin >> bx[i] >> by[i];
        gbx += bx[i];
        gby += by[i];
    }
    gax /= n;
    gay /= n;
    gbx /= n;
    gby /= n;//移動前、移動後の重心座標

    double a = 0,b = 0;
    REP(i,n){
        a += (gax-ax[i])*(gax-ax[i]) + (gay-ay[i])*(gay-ay[i]);
        b += (gbx-bx[i])*(gbx-bx[i]) + (gby-by[i])*(gby-by[i]);
    }
    double ans = sqrt(b/a);
    //double ans = b/a;
    printf("%.12f\n",ans);



    return 0;
}
