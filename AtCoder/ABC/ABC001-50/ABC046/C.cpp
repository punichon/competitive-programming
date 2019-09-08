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

    ll n,t,a,A=1,B=1;
    cin >> n;
    ll j = 1;
    REP(n){
        
        ll tmp;
        cin >> t >> a;
        if(A/t == 0 && B/a == 0){
            tmp = 1;
        }else{
            tmp = max((A+t-1)/t,(B+a-1)/a);
        }
        //cout << tmp << endl;
        A = t*tmp;
        B = a*tmp;
        //cout << A << " " << B << endl;
    }


    cout << A+B << endl;





    return 0;
}
