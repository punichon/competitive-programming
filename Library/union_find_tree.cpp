
typedef struct union_find{
    
    vector<int> pa;//親
    vector<int> ra;//木の深さ
    //n要素で初期化
    void init(int n){
        pa.resize(n);
        ra.resize(n);
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


//繋げる方向を一方向にする
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
    }

    //xとyが同じ集合に属するか判定
    bool same(ll x,ll y){
        return find(x) == find(y);//同じ集合なら1、違うなら0が返る
    }
}UF;


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