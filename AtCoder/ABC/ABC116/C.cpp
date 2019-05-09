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

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
typedef pair<ll,ll> pll;
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
#define MOD 1000000007
#define ARRAY_MAX 100005

const int INF = 1e9+7;


int main(){

    int n;
    ll ans = 0;
    cin >> n;
    vector<int> h(n);
    int mini = INF;
    REP(i,n){
        cin >> h[i];
    }

    while(true){

        bool num = false;
        for(int i = 0;i < n;i++){
            num |= h[i];
        }

        if(!num){
            break;
        }

        //まだ伸ばせる
        
        int maxi = -1;
        int mini = INF;
        int left = 0;
        while(h[left] == 0 && left < n){
            left++;
        } 
        //0でないものが出てきた
        int right = left;
        while(right < n && h[right] != 0){
            mini = min(mini,h[right]);
            right++;
        }

        ans += mini;
        for(int i = right-1;i >= left;i--){
            h[i] -= mini;
        }
    }

    cout << ans << endl;



    return 0;
}
