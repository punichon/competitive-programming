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

    ll n;
    cin >> n;
    ll depth = 0;
    for(ll i = n;i>0 ; i/=2){
        depth++;
    }
       
    ll ans = 0;

    string s[2];
    s[0] = "Aoki";
    s[1] = "Takahashi";
    int option = 0;

    if(depth % 2 == 1){
        //cout << "aa" << endl;
        ll count = 1;
        ll sum = 0;
        //cout << count << endl;
        while(count <= n){
            //cout << "e" << endl;
            if(sum % 2 == 0){
                //cout << "b" << endl;
                count = count * (2LL) + 1LL;
            }else{
                //cout << "c" << endl;
                count = count * (2LL);
            }
            sum++;
        }
        //cout << sum << endl;
        //cout << count << endl;
        
        if(sum % 2 == 1){
            option = 0;
        }else{
            option = 1;
        }
    }else{

         //cout << "aa" << endl;
         ll count = 1;
         ll sum = 0;
         //cout << count << endl;
         while(count <= n){
             //cout << "e" << endl;
             if(sum % 2 == 0){
                 //cout << "b" << endl;
                 count = count * (2LL);
             }else{
                 //cout << "c" << endl;
                 count = count * (2LL) + 1LL;
             }
             sum++;
         }
         //cout << sum << endl;
         //cout << count << endl;
         
         if(sum % 2 == 1){
             option = 0;
         }else{
             option = 1;
         }
    }

    cout << s[option] << endl;
    return 0;
}
