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

int k,n;
vector<string> v,w;
string ans[10];
int len[10];


bool check(){

    for(int i = 0;i < n;i++){
        //文字数チェック
        int sum = 0;
        for(int j = 0;j < v[i].size();j++){//i番目のvについてj桁目の数字に対応する文字列の長さを加算
            sum += len[v[i][j]-'0']; 
        }
        if(sum != w[i].size()){//文字数が一致していないなら不適
            return false;
        }
        //ここからは文字数は一致していた場合の処理

        int posi = 0;//部分文字列の始点
        for(int j = 0;j < v[i].size();j++){

            string s = w[i].substr(posi,len[v[i][j]-'0']);//w[i]のposiからlen[v[i][j]-'0']文字の部分列を取り出す
            posi += len[v[i][j]-'0'];

            if(ans[v[i][j]-'0'].size() == 0){
                //まだ何も文字が入っていないならとりあえず入れておく
                ans[v[i][j]-'0'] = s;
            }else{
                if(ans[v[i][j]-'0'] != s){//既に入っている文字を一致しないのでこの選び方は不適
                    return false;
                }
            }
        }
    }
    return true;
}


int dfs(int now){//now文字目の長さを決める

    if(now == 10){//9までの数字に対応する文字の仮の長さが求まった

        string emp = "";
        for(int i = 0;i < 10;i++){
            ans[i] = emp;
        }
        return check();
    }

    for(int i = 1;i <= 3;i++){
        len[now] = i;//now文字目の長さをiとする
        if(dfs(now+1)){
            return 1;
        }
    }
    return 0;
}

int main(){

    cin >> k >> n;
    for(int i = 0;i < n;i++){
        string a,b;
        cin >> a >> b;
        v.push_back(a);
        w.push_back(b);
    }

    dfs(1);

    for(int i = 1;i <= k;i++){
        cout << ans[i] << endl;
    }


    return 0;
}
