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

    ll a,b,c,d;
    cin >> a >> b >> c >> d;

    if(a*b == c*d){
        cout << a*b << endl;
    }else if(a*b > c*d){
        cout << a*b << endl;
    }else{
        cout << c*d << endl;
    }

    return 0;
}
