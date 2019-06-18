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
#define INF 1000000000007
#define MOD 1000000007
#define ARRAY_MAX 3005


//重み付きUnion-Find
struct Potential_UnionFind{

    vector<int> par;//親
    vector<int> rank;//高さ
    vector<int> diff_weight;//根からの重み

    void init(int n) {
        par.resize(n);
        rank.resize(n);
        diff_weight.resize(n);
        REP(i,n){
            par[i] = i;
            rank[i] = 0;
            diff_weight[i] = 0;
        }
    }

    int root(int x) {//親を探す
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    int weight(int x) {
        //親からの重みを返す
        root(x);
        return diff_weight[x];
    }

    bool issame(int x,int y) {
        //同じ親を持つ要素かどうか
        return root(x) == root(y);
    }

    void merge(int x, int y,int w) {
        //weight(y) - weight(x) = wとなるようにつなげる
        int rx = root(x);
        int ry = root(y);
        
        if(rank[rx] < rank[ry]){
            diff_weight[rx] = -w - weight(x) + weight(y);
            par[rx] = ry;
        }else{
            diff_weight[ry] = w + weight(x) - weight(y);
            par[ry] = rx;
            if(rank[rx] == rank[ry]){
                rank[rx]++;
            }
        }
    }

    int diff(int x, int y) {
        //weight(y) - weight(x)を返す
        return weight(y) - weight(x);
    }
};


int main(){

    Potential_UnionFind tree;
    int n,m;
    cin >> n >> m;
    tree.init(n);
    bool ans = true;

    for(int i = 0;i < m;i++){

        int l,r,d;
        cin >> l >> r >> d;
        l--;
        r--;
        if(tree.issame(l,r)){
            int distance = tree.diff(l,r);//r-l;
            if(distance != d){
                ans = false;
                break;
            }
        }else{
            tree.merge(l,r,d);
        }
    }

    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }


    return 0;
}
