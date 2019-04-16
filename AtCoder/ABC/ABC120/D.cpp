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



typedef struct union_find{
    
    vector<ll> pa;//親
    vector<ll> ra;//木の深さ
    vector<ll> siz;
    //n要素で初期化
    void init(ll n){
        pa.resize(n);
        ra.resize(n);
        siz.resize(n);
        for(ll i = 0;i < n;i++){
            pa[i] = i;/*各ノードに番号を振る,この時par[x]=xとなる時は木の根となる*/
            ra[i] = 0LL;/*各ノード自体の高さは0*/
            siz[i] = 1LL;
        }
    }
    //木の根を求める
    ll find(ll x){
        if(pa[x] == x){
            return x;/*根ならそのノードの番号を返す*/
        }else{
            return pa[x] = find(pa[x]);/*根でないならさらにノードの根を探す*/
        }
    }

    //xとyの属する集合を併合する
    void unite(ll x,ll y){
        x = find(x);//xの根の番号を探す
        y = find(y);//yの根の番号を探す
        if(x == y){//一致すればつながっている
            return;
        }
        pa[y] = x;
        siz[x] += siz[y];
        /*if(ra[x] < ra[y]){//xの高さが低いなら高いほうにつなぐ、そして高さは大きい方(y)になる
        }else{
            pa[y] = x;//yの高さが低いなら高いほうにつなぐ、そして高さは大きいほう(x)になる
            siz[x] += siz[y];
            if(ra[x] == ra[y]){//高さが一致しているなら併合の高さは1増える
                ra[x]++;
            }
        }*/
    }

    //xとyが同じ集合に属するか判定
    bool same(ll x,ll y){
        return find(x) == find(y);//同じ集合なら1、違うなら0が返る
    }
}UF;


int main(){

    ll n,m;
    cin >> n >> m;
    UF tree;
    tree.init(n);

    vector<ll> a(m),b(m);
    for(ll i = 0;i < m;i++){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }
    vector<ll> ans;
    ans.push_back((n*(n-1))/2);

    ll tmp = (n*(n-1))/2;

    for(ll i = m-1;i >= 0;i--){

        if(tmp == 0){
            ans.push_back(0);
            continue;
        }
        ll diff1 = tree.siz[tree.find(a[i])];
        ll diff2 = tree.siz[tree.find(b[i])];
        if(tree.same(a[i],b[i])){
            ans.push_back(tmp);
            tree.unite(a[i],b[i]);
            continue;
        }
        tree.unite(a[i],b[i]);
        //a←bにつなげる
        if(diff1 == 1LL && diff2 == 1LL){
            //両方1個ずつしかない場合
            tmp--;
        }else{
            ll node = tree.siz[tree.find(a[i])];//つなげた後のノードの個数
            tmp = tmp - ((node*(node-1))/2  - (diff1*(diff1-1))/2 - (diff2*(diff2-1))/2 );
        }
        ans.push_back(tmp);
    }

    for(int i = ans.size()-2;i >= 0;i--){
        cout << ans[i] << endl;
    }


    return 0;
}
