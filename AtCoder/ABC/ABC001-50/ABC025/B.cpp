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
#include<queue>

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
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
#define INF 1000000007
#define MOD 1000000007
#define ARRAY_MAX 100005

int main(){

    int n,A,B,distance;
    int ans = 0;//Eastを正
    cin >> n >> A >> B;
    string s;
    REP(i,n){
        cin >> s >> distance;
        if(s.substr(0,4) == "East"){
            if(distance < A){
                ans += A;
            }else if(distance > B){
                ans += B;
            }else{
                ans += distance;
            }
        }else{
            if(distance < A){
                ans -= A;
            }else if(distance > B){
                ans -= B;
            }else{
                ans -= distance;
            }
        }
    }

    if(ans == 0){
        cout << "0" << endl;
    }else if(ans > 0){
        cout << "East " << abs(ans) << endl;
    }else{
        cout << "West " << abs(ans) << endl;
    }

    return 0;
}
