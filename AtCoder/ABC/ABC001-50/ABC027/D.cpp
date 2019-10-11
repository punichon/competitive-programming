#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<climits>
#include<cstdio>

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
#define INF 1000000007

#define ARRAY_MAX 100005

int a[ARRAY_MAX];//a[i+1]:iまでの+の数
int b[ARRAY_MAX];

int main(){

    string s;
    cin >> s;
    int sum_plus = 0;
    int sum_minus = 0;
    vector<int> vec;

    REP(i,s.length()){
        if(s[i] == '+'){
            a[i+1]++;
            sum_plus++;
        }
        if(s[i] == '-'){
            b[i+1]++;
            sum_minus++;
        }
    }
    REP(i,ARRAY_MAX-1){
        a[i+1] += a[i];
    }
    REP(i,ARRAY_MAX-1){
        b[i+1] += b[i];
    }

    REP(i,s.length()){
        if(s[i] == '+' || s[i] == '-'){
            continue;
        }
        int plus = sum_plus - a[i+1];
        int minus = sum_minus - b[i+1];
        vec.push_back(plus-minus);   
    }
    VSORT(vec);
    int front = 0;
    int back = 0;
    REP(i,vec.size()/2){
        front += vec[i];
    }
    for(int i = vec.size()/2;i < vec.size();i++){
        back += vec[i];
    }
    cout << back - front << endl;
    return 0;
}
