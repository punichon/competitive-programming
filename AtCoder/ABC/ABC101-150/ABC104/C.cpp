#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>

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

int main(){

    ll n;
    cin >> n;
    string s="";
    if(n == 0){
        cout << '0' << endl;
    }else{

        while(n!= 0){

            if(n%2 != 0){
                s += '1';
                n--;
            }else{
                s += '0';
            }
            n /= -2;
        }
        reverse(s.begin(),s.end());
        cout << s << endl;
    }

    return 0;
}
