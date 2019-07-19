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

const ll INF = 1e17+7;


int main(){

    ll n;
    cin >> n;
    int siz = 3*n;
    vector<ll> vec(siz);
    for(int i = 0;i < siz;i++){
        cin >> vec[i];
    }

    priority_queue<ll,vector<ll>,greater<ll> > que_add;//小さい方から取り出す
    priority_queue<ll> que_sub;//大きい方から取り出す

    vector<ll> ad,sb;
    ll cnt_add = 0,cnt_sub = 0;

    for(int i = 0;i < n;i++){
        //前半n要素をあらかじめ追加
        que_add.push(vec[i]);
        cnt_add += vec[i];
    }
    for(int i = siz-1;i >= siz-n;i--){
        //後半n要素をあらかじめ追加
        que_sub.push(vec[i]);
        cnt_sub += vec[i];
    }

    ad.push_back(cnt_add);//前半に何も入れない場合(残りは全て後ろに埋めるケース)
    sb.push_back(cnt_sub);//後半に何も入れないケース

    ll left = n;
    ll right = siz-n-1;

    for(int i = n;i < 2*n;i++){
        //真ん中n要素について調べる
        //i番目まで見た時の前半の最大値
        ll tmp = que_add.top();
        if(tmp < vec[i]){
            que_add.pop();
            que_add.push(vec[i]);
            cnt_add += (vec[i] - tmp);
        }
        ad.push_back(cnt_add);
    }

    for(int i = 2*n-1;i >= n;i--){
        //真ん中n要素について調べる
        //i番目まで見た時の前半の最大値
        ll tmp = que_sub.top();
        if(tmp > vec[i]){
            que_sub.pop();
            que_sub.push(vec[i]);
            cnt_sub -= (tmp - vec[i]);
        }
        sb.push_back(cnt_sub);
    }

    reverse(sb.begin(),sb.end());

    ll maxi = -INF;
    for(int i = 0;i < ad.size();i++){
        maxi = max(maxi,ad[i]-sb[i]);
    }

    cout << maxi << endl;

    return 0;
}
