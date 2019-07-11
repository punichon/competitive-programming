#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int ll;

ll gcd(ll a,ll b);
ll lcm(ll a,ll b);

int main(){

    int n;
    cin >> n;
    ll ans = 1;
   
    for(int i = 0;i < n;i++){
        ll tmp = 0;
        cin >> tmp;
        
        ans = lcm(ans,tmp);
    }
       
    cout << ans << endl;

    return 0;
}

ll gcd(ll a,ll b){

    if(b == 0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}

ll lcm(ll a,ll b){

    ll tmp = gcd(a,b);
    return a/tmp*b;
}

