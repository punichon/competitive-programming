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
#define ARRAY_MAX 1005

const int INF = 1e9+7;


int main(){

    int s;
    cin >> s;

    vector<int> a(ARRAY_MAX,0);

    a[0] = s;
    for(int i = 1;i <= ARRAY_MAX;i++){

        if(a[i-1]%2 == 0){
            a[i] = a[i-1]/2;
        }else{
            a[i] = 3*a[i-1] + 1;
        }
    }

    int mini = INF;
    for(int i = 0;i < ARRAY_MAX;i++){
        for(int j = i+1;j < ARRAY_MAX;j++){
            if(a[i] == a[j]){
                mini = min(j,mini);
            }
        }
    }
    cout << mini+1 << endl;






    return 0;
}
