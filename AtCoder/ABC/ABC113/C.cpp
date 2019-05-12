#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<numeric>
#include<map>
#include<cstdio>

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


typedef struct mp{

    int pre;
    int year;
    int index;

}MP;

bool comp(const MP& a,const MP& b){

    if(a.pre == b.pre){
        return a.year < b.year;
    }else{
        return a.pre < b.pre;
    }
}


int main(){

    ll n,m;
    cin >> n >> m;
    vector<MP> a(m);
    vector<string> ans(m);
    vector<int> count(n,1);//n番目の県で何番目かを記録
    REP(i,n){
        count[i] = 1;
    }

    REP(i,m){
        cin >> a[i].pre >> a[i].year;
        a[i].index = i;
    }
    sort(a.begin(),a.end(),comp);
    /*REP(i,m){
        printf("%d %d %d\n",a[i].pre,a[i].year,a[i].index);
    }*/

    REP(i,m){
        string tmp = to_string(a[i].pre);
        int len = tmp.length();
        REP(j,6-len){
            ans[a[i].index].push_back('0');
        }
        ans[a[i].index]+=tmp;
        //
        string tmp2 = to_string(count[a[i].pre-1]);
        int len2 = tmp2.length();
        //cout << len2 << " " << tmp2 << endl;
        REP(j,6-len2){
            ans[a[i].index].push_back('0');
        }
        ans[a[i].index]+=tmp2;
        count[a[i].pre-1]++;
    }

    REP(i,m){
        cout << ans[i] << endl;
    }

    return 0;
}
