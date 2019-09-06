#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>

#define REP(n) for(int i = 0;i < n;i++)
#define LLREP(n) for(long long int  i = 0;i < n;i++)
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
#define MAX_A 1000000007

ll f(ll n,ll x){

    if(n == -1){
        return 0;
    }else{
        return (n/x+1);
    }
}


int main(){

    ll a,b,x;
    cin >> a >> b >> x;

    ll f_a = f(a-1,x);
    ll f_b = f(b,x);
    //cout << f_a << " " << f_b << endl;

    cout << f_b-f_a << endl;


    return 0;
}
