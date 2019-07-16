#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include <numeric>


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
#define ARRAY_MAX 100005

vector<int> par(ARRAY_MAX);//親
vector<int> ran(ARRAY_MAX);//木の深さ

typedef struct edge{

    int u;
    int v;
    int cost;

}EDGE;

typedef struct where{

    int num;
    int x;
    int y;

}WHERE;

bool comp(const EDGE& e1,const EDGE& e2){
    return e1.cost < e2.cost;
}


bool compx(const WHERE& e1,const WHERE& e2){
    return e1.x < e2.x;
}


bool compy(const WHERE& e1,const WHERE& e2){
    return e1.y < e2.y;
}


//n要素で初期化
void init(int n){
    for(int i = 0;i < n;i++){
        par[i] = i;/*各ノードに番号を振る,この時par[x]=xとなる時は木の根となる*/
        ran[i] = 0;/*各ノード自体の高さは0*/
    }
}
//木の根を求める
int find(int x){
    if(par[x] == x){
        return x;/*根ならそのノードの番号を返す*/
    }else{
        return par[x] = find(par[x]);/*根でないならさらにノードの根を探す*/
    }
}

//xとyの属する集合を併合する
void unite(int x,int y){
    x = find(x);//xの根の番号を探す
    y = find(y);//yの根の番号を探す
    if(x == y){//一致すればつながっている
        return;
    }
    if(ran[x] < ran[y]){//xの高さが低いなら高いほうにつなぐ、そして高さは大きい方(y)になる
        par[x] = y;
    }else{
        par[y] = x;//yの高さが低いなら高いほうにつなぐ、そして高さは大きいほう(x)になる
        if(ran[x] == ran[y]){//高さが一致しているなら併合の高さは1増える
            ran[x]++;
        }
    }
}

//xとyが同じ集合に属するか判定
bool same(int x,int y){
    return find(x) == find(y);//同じ集合なら1、違うなら0が返る
}

int kruskal(int n,int count,vector<EDGE>& es){

    sort(es.begin(),es.end(),comp);
    init(n);
    int res = 0;
    for(int i = 0;i < count;i++){
        EDGE e = es[i];
        if(!same(e.u,e.v)){
            unite(e.u,e.v);
            res += e.cost;
        }
    }
    return res;
}



int main(){

    int n;
    cin >> n;
    vector<EDGE> es;
    vector<WHERE> map(n);
    int count = 0;

    REP(i,n){
        map[i].num = i;
        cin >> map[i].x >> map[i].y;
    }

    sort(map.begin(),map.end(),compx);

    for(int i = 0;i < n-1;i++){
        EDGE e;
        e.u = map[i].num;
        e.v = map[i+1].num;
        e.cost = map[i+1].x - map[i].x;/*昇順ソート済み*/
        es.push_back(e);
        count++;
    }


    sort(map.begin(),map.end(),compy);
    
    for(int i = 0;i < n-1;i++){
        EDGE e;
        e.u = map[i].num;
        e.v = map[i+1].num;
        e.cost = map[i+1].y - map[i].y;/*昇順ソート済み*/
        es.push_back(e);
        count++;
    }
    
    /*
    cout << count << endl;
    REP(i,es.size()){
        cout << es[i].u << " " << es[i].v << " " << es[i].cost << endl;
    }
    */


    int ans = kruskal(n,count,es);
    cout << ans << endl;



    return 0;
}
