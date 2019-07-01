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
#include<queue>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef long long int ll;
ll dx[4] = {1,0,0,-1};
ll dy[4] = {0,1,-1,0};

#define ARRAY_MAX 205
int mp[ARRAY_MAX][ARRAY_MAX];
int magic[ARRAY_MAX][ARRAY_MAX];
int h,w;

int main(){

    cin >> h >> w;
    REP(i,10){
        REP(j,10){
            cin >> mp[i][j];
        }
    }
    REP(i,h){
        REP(j,w){
            cin >> magic[i][j];
        }
    }

    vector<int> mini(10,INF);//iから1にするのに必要な最小コスト
    vector<int> num(10);
    mini[1] = 0;
    REP(i,10){
        num[i] = i;
    }

    do{
        int power = 0;
        if(num[0] == 1){
            continue;
        }
        REP(i,9){
            power += mp[num[i]][num[i+1]];
            if(num[i+1] == 1){
                break;
            }
        }
        mini[num[0]] = min(mini[num[0]],power);

    }while(next_permutation(num.begin(),num.end()));

    int ans = 0;
    REP(i,h){
        REP(j,w){
            if(magic[i][j] == -1){
                continue;
            }
            ans += mini[magic[i][j]];
        }
    }
    cout << ans << endl;

    return 0;
}
