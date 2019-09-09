#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<map>

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

    
    string s;
    cin >> s;
    

    ll s_length = s.length()-1;
    

    ll ans = 0;

    REP(i, (1<<s_length)){
        ll tmp = 0;
        ll sum = 0;
        tmp = s[0]-'0';


        REP(j,s_length){

            if((i>>j) &1){
                sum += tmp;
                tmp = s[j+1]-'0';
            }else{
                tmp = tmp*10 + s[j+1]-'0';
            }

        }
        sum += tmp;
        ans += sum;
       
    }
    
    cout << ans << endl;



    return 0;
}
