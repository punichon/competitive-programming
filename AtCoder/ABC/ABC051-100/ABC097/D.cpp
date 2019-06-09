#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cstring>
#include<cmath>
#include <numeric>
#include<queue>
#include<climits>
#include<cstdio>
#include<map>


#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
//#define INF ((LLONG_MAX) / (2))
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef long long int ll;
typedef pair<ll,int> LL_IP;
typedef pair<ll,ll> LL_LLP;
#define INF 1000000007
#define MAX_H 20000

#define ARRAY_MAX 100005

typedef struct union_find{
    
    int pa[ARRAY_MAX];
    int ra[ARRAY_MAX];  
    //vector<int> pa(ARRAY_MAX);//親
    //vector<int> ra(ARRAY_MAX);//木の深さ
    //n要素で初期化
    void init(int n){
        for(int i = 0;i < n;i++){
            pa[i] = i;/*各ノードに番号を振る,この時par[x]=xとなる時は木の根となる*/
            ra[i] = 0;/*各ノード自体の高さは0*/
        }
    }
    //木の根を求める
    int find(int x){
        if(pa[x] == x){
            return x;/*根ならそのノードの番号を返す*/
        }else{
            return pa[x] = find(pa[x]);/*根でないならさらにノードの根を探す*/
        }
    }

    //xとyの属する集合を併合する
    void unite(int x,int y){
        x = find(x);//xの根の番号を探す
        y = find(y);//yの根の番号を探す
        if(x == y){//一致すればつながっている
            return;
        }
        if(ra[x] < ra[y]){//xの高さが低いなら高いほうにつなぐ、そして高さは大きい方(y)になる
            pa[x] = y;
        }else{
            pa[y] = x;//yの高さが低いなら高いほうにつなぐ、そして高さは大きいほう(x)になる
            if(ra[x] == ra[y]){//高さが一致しているなら併合の高さは1増える
                ra[x]++;
            }
        }
    }

    //xとyが同じ集合に属するか判定
    bool same(int x,int y){
        return find(x) == find(y);//同じ集合なら1、違うなら0が返る
    }
}UF;

UF num;

int main(){

    int n,m;
    cin >> n >> m;
    vector<int> arr(n);
    REP(i,n){
        cin >> arr[i];
        arr[i]--;
    }
    num.init(n);

    REP(i,m){
        int a,b;
        cin >> a >> b;
        a--;
        b--;//配列の添え字に合わせる
        num.unite(a,b);
    }

    int ans = 0;
    REP(i,n){

        if(num.same(i,arr[i])){
            ans++;
        }
    }
    cout << ans << endl;


    return 0;
}
