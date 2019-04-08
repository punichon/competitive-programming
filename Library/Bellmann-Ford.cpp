#include<iostream>
#include<cstring>
using namespace std;

#define MAX_V 100
#define INF 100000

struct edge{
    int from;
    int to;
    int cost;
};

struct edge es[MAX_V];


int d[MAX_V];
int V,E;

/*頂点sから各頂点への最短距離を求めること、頂点sから到達できる負閉路があれば真が返る、目的地が決まっていないバージョン*/
/*V-1回の更新で各ノードへの最短距離は求められるが、V回目の更新が起こった場合は負閉路が存在していることになる*/
bool shortest_path(int v,int e,int s,vector<EDGE>& arr,vector<int>& d,vector<int>& prev){
    /*頂点の個数、辺の個数、始点となる頂点、辺の情報、最短距離*/
    for(int i = 0;i < d.size();i++){
        d[i] = INF;
    }
    d[s]=0;
    
    for(int i = 0;i < v;i++){
        for(int j = 0;j < e;j++){
            EDGE tmp = arr[j];
            if(d[tmp.from] != INF && d[tmp.to] > d[tmp.from] + tmp.cost){
                d[tmp.to] = d[tmp.from] + tmp.cost;
                prev[tmp.to] = tmp.from;
                if(i == v-1){
                    return true;
                }

            }
        }
    }
    return false;
}


/*負のコストがあるか調べる（蟻本）*/
/*これは始点から到達可能か否かに関わらずグラフ内に負閉路が存在するときに真が返る*/
bool find_nagative_loop(int v,int e,vector<EDGE>& arr,vector<int>& d,vector<int>& prev){
    /*頂点の個数、辺の個数、辺の情報、最短距離*/
    //全ての最短経路を0で初期化
    for(int i = 0;i < d.size();i++){
        d[i] = 0;
    }

    for(int i = 0;i < v;i++){
        for(int j = 0;j < e;j++){
            EDGE tmp = arr[j];
            if(d[tmp.to] > d[tmp.from] + tmp.cost){
                d[tmp.to] = d[tmp.from] + tmp.cost;
                prev[tmp.to] = tmp.from;
                if(i == v-1){
                    return true;
                }
            }
        }
    }
    return false;
}


/*頂点sから各頂点への最短距離を求めること、頂点sから到達できる負閉路があれば真が返る、目的地が決まっているバージョン*/
/*V-1回の更新で各ノードへの最短距離は求められる*/
/*V回目から2V回目までに最短距離が更新される場合は目的地を含む負閉路が存在する*/
bool shortest_path(int v,int e,int s,int t,vector<EDGE>& arr,vector<int>& d,vector<int>& prev){
    /*頂点の個数、辺の個数、始点となる頂点、目的地の頂点、辺の情報、最短距離*/
    for(int i = 0;i < d.size();i++){
        d[i] = INF;
    }
    d[s]=0;
    
    for(int i = 0;i < 2*v;i++){
        for(int j = 0;j < e;j++){
            EDGE tmp = arr[j];
            if(d[tmp.from] != INF && d[tmp.to] > d[tmp.from] + tmp.cost){
                d[tmp.to] = d[tmp.from] + tmp.cost;
                prev[tmp.to] = tmp.from;
                if(i >= v-1 && tmp.to == t){
                    return true;
                }

            }
        }
    }
    return false;
}


/*頂点tへの最短経路*/
vector<int> get_path(int t,vector<int>& prev){
    /*目的地の頂点、直前の頂点の情報*/

    vector<int> path;
    for(; t != -1;t = prev[t]){
        path.push_back(t);
    }

    reverse(path.begin(),path.end());/*このままだと目的地から始点の順になっているので逆順にする*/
    return path;
}












int main(){



    return 0;
}