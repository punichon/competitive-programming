#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>

#define REP(n) for(int i = 0;i < n;i++)
#define LLREP(n) for(long long int  i = 0;i < n;i++)
typedef long long int ll;
using namespace std;
#define MAX_A 100005

int main(){

    ll a,b,k;
    cin >> a >> b >> k;

    if(a+k > b-k+1){
        for(ll i = a;i <=b;i++){
            cout << i << endl;
        }
    }else{
        for(ll i = a;i < a+k;i++){
            cout << i << endl;
        }
        for(ll i = b-k+1;i <=b;i++){
            cout << i << endl;
        }


    }


    return 0;
}
