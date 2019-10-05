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

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 1000000000
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef long long int ll;

#define ARRAY_MAX 505

int main(){

    ll n,m,x,y;
    cin >> n >> m >> x >> y;
    vector<ll> a(n),b(m);
    REP(i,n){
        cin >> a[i];
    }
    REP(i,m){
        cin >> b[i];
    }
    vector<ll>::iterator itr;
    bool flag = true;//true:a→b false:b←a
    ll now_time = 0;
    ll count = 0;
    bool next = true;

    while(next){


        if(flag){
            //AからB
            if((itr = lower_bound(a.begin(),a.end(),now_time)) != a.end()){
                now_time = *itr + x;
                flag = !flag;
            }else{
                next = false;
            }
        }else{
             //BからA
            if((itr = lower_bound(b.begin(),b.end(),now_time)) != b.end()){
                now_time = *itr + y;
                count++;
                flag = !flag;
            }else{
                next = false;
            }
        }
    }
    cout << count << endl;





    return 0;
}
