#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>

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

    ll n,h;
    cin >> n >> h;
    vector<ll> a(n),b(n);
    REP(i,n){
        cin >> a[i] >> b[i]; 
    }

    sort(a.begin(),a.end(),greater<ll>());
    sort(b.begin(),b.end(),greater<ll>());
    
    ll cut_damage = a[0];
    ll count = 0;

    bool flag = true;/*操作の継続条件*/

    while(flag){

        for(int i = 0;i < n;i++){
            /*切るダメージが投げるダメージを超えるまではひたすら投げる*/
            if(h <= 0){
                flag = false;
                break;
            }

            if(b[i] <= cut_damage){
                /*切るダメージのほうが大きくなるので投げるのを終了*/
                break;
            }else{
                /*投げるダメージのほうが大きい*/
                if(b[i] >= h){
                    /*この投げる操作でダメージが0になるのでカウントして操作を終了する*/
                    count++;
                    flag = false;
                    h -= b[i];
                }else{
                    /*投げてダメージを減らす*/
                    h -= b[i];
                    count++;
                }
            }
        }

        if(h <= 0){
            break;
        }

        /*この時点で残りは切るのみ*/


        if(h % cut_damage == 0){
            count += h/cut_damage;
            flag = false;
        }else{
            count += h/cut_damage + 1;
            flag = false;
        }
    }
    cout << count << endl;
    return 0;
}
