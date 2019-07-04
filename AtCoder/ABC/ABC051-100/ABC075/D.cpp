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
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
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
#define INF 1e9+7


int main(){

    ll N,K;
    cin >> N >> K;
    vector<ll> x(N),y(N),xarr,yarr;
    REP(i,N){
        cin >> x[i] >> y[i];
        xarr.push_back(x[i]);
        yarr.push_back(y[i]);
    }
    VSORT(xarr);
    VSORT(yarr);

    ll ans = (xarr[N-1]-xarr[0]) * (yarr[N-1]-yarr[0]);

    for(int lx = 0; lx < N;lx++){

        for(int rx = lx+1;rx < N;rx++){

            for(int oy = 0;oy < N;oy++){

                for(int uy = oy+1;uy < N;uy++){

                    ll num = 0;
                    ll le_x = xarr[lx];
                    ll ri_x = xarr[rx];
                    ll ov_y = yarr[oy];
                    ll un_y = yarr[uy];

                    for (int i = 0; i < N; i++){
                        if(le_x <= x[i] && x[i] <= ri_x && ov_y <= y[i] && y[i] <= un_y){
                            num++;
                        }
                    }
                    if(num >= K){
                        ans = min(ans,(ri_x-le_x) * (un_y-ov_y));
                    }
                }
            }
        }
    }
    cout << ans << endl;


    return 0;
}
