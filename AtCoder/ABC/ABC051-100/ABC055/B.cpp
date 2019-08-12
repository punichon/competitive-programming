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

    ll n,power = 1;
    cin >> n;

    REP(n){

        power = power*(i+1)%MAX_A;

    }
    cout << power << endl;


    return 0;
}
