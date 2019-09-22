#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>

#define REP(n) for(int i = 0;i < n;i++)
#define LLREP(n) for(long long int  i = 0;i < n;i++)
typedef long long int ll;
using namespace std;
#define MAX_A 100000

int main(){

    ll x;
    cin >> x;
    for(ll i = 1;i < 1000;i++){

        if(i*i*i*i == x){
            cout << i << endl;
            return 0;
        } 
    }
    return 0;
}
