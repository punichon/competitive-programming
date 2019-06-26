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
#include<bitset>

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

const int M = 8005;

bitset<M*2> xbit,ybit;

int main(){

    string s;
    cin >> s;
    int x,y;
    cin >> x >> y;
    int len = s.length();

    int cnt = 0;
    while(cnt < len && s[cnt] == 'F'){
        cnt++;
    }
    //Mを初期位置とする
    xbit[M+cnt] = 1;
    ybit[M] = 1;
    int mode = 1;//x方向 or y方向

    int cc = 0;
    while(cnt <= len){
    
        if(s[cnt] == 'F'){
            cc++;
        }else{
            if(mode == 1){
                xbit = (xbit << cc) | (xbit >> cc);
            }else{
                ybit = (ybit << cc) | (ybit >> cc);
            }
            mode ^= 1;
            cc = 0;
        }
        cnt++;
    }

    if(xbit[M + x] & ybit[M + y]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }



    return 0;
}
