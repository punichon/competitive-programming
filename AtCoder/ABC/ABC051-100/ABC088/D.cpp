#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAX_N 100
#define MAX_M 100

const int INF =  100000000;
typedef pair<int,int> P;
//2つの型の異なる、あるいは同じ型の値をまとめて管理するクラステンプレート

int N,M;
char maze[MAX_N][MAX_M + 1];//迷路
int sx,sy;//スタート
int gx,gy;//ゴール
int d[MAX_N][MAX_M];//最短距離
int dx[4] = {1,0,-1,0};//x方向
int dy[4] = {0,1,0,-1};//y方向
int ans = 0;
int black = 0;


//たどり着けないところはINF
void bfs(){

    queue<P> que;//pair のキューの定義
    for(int i = 0 ; i < N;i++){
        for(int j = 0 ;j < M ;j++){
            d[i][j] = INF;//全ての点をINFで初期化
        }
    }
    //スタートの位置をキューに入れ、その点に0を代入する
    que.push(P(sx,sy));
    d[sx][sy] = 0;

    //キューが空になるまでループ
    while(que.size()){
        //取り出した状態がゴールなら探索終了
        P p = que.front(); que.pop();
        if(p.first == gx && p.second == gy){
            break;
        }
        //移動方向をループして探索
        for(int i = 0;i < 4;i++){
            int nx = p.first + dx[i], ny = p.second + dy[i];
            //移動可能か、また、すでに訪れているかの判定
            if(0<=nx && nx < N && 0<=ny && ny < M && maze[nx][ny] != '#' && d[nx][ny] == INF){
                que.push(P(nx,ny));
                //移動できるならその点をpからの距離+1する
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }         
    }
    return;
}

void solve(){
    bfs();
    //cout << res << endl;
}


int main(){

    cin >> N >> M;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            cin >> maze[i][j];
            /*if(maze[i][j] == 'S'){
                sx = i; sy = j;
            }
            if(maze[i][j] == 'G'){
                gx = i; gy = j;
            }*/
        }
    }
    sx = 0;sy=0;
    gx=N-1;gy=M-1;
    
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            if(maze[i][j] == '#'){
                black++;
            }
        }
    }

    solve();

    if(d[N-1][M-1]== INF){
        cout << "-1" << endl;
    }else{
        cout << N*M -black - d[N-1][M-1]-1 << endl;
    }
    return 0;
}
