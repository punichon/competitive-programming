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
#define MAX_A 1000000007

int main(){

    ll n,k;
    cin >> n >> k;

    ll ans = 1;
    
    for(int i = 0;i < n-1;i++){
        ans*=(k-1);
    }
    ans*=k;

    cout << ans << endl;

    return 0;
}
