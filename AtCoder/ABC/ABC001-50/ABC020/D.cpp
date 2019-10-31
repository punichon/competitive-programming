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

    ll n,k;
    cin >> n >> k;
    vector<ll> vec;//gcd(i,k)=hogeを格納

    for(ll i = 1;i*i <= k;i++){
        if(k % i){
            continue;
        }
        vec.push_back(i);
        vec.push_back(k / i);
    }
    sort(vec.begin(),vec.end(),greater<ll>());

    ll ans = 0;
    ll siz = vec.size();

    vector<ll> s(siz,0);

    for(ll i = 0;i < siz;i++){
        //大きい方から見る
        //約数がhogeとなる整数の集合を考える
        ll r = (n /vec[i]) * vec[i];//約数がvec[i]となるものでn以下の最大の数
        s[i] = (vec[i] + r)*(n/vec[i])/2;//約数がhogeとなる整数の総和

        for(int j = 0;j < i;j++){

            if(vec[j] % vec[i]){
                continue;
            }
            //約数の倍数以外の場合は除く
            //約数がxの集合から約数が2x、3x、・・・となる集合を引いておく
            //大きい方から見ていくと２回引かなくなる
            //1の場合、2,3,4,・・・と引いていくが、大きい方から見ていくことで、2,3において6の倍数を２回引かなくなる
            //3の時に6の倍数が引かれ、2の時に6の倍数が独立に引かれる
            s[i] = s[i] - s[j];
        }
        //s[i]は整数の和なのでs[i]/gcd(i,k)のようにgcdで割る
        ans = (ans + s[i] / vec[i]) % MOD;
    }
    cout << ans * k % MOD << endl;//最後に定数として置いておいたkをかける


    return 0;
}
