#include<iostream>
#include<algorithm>
using namespace std;

typedef long long int ll;

int main(){

    ll n,s,t,w = 0,a,ans = 0;
    cin >> n >> s >> t >> w;
    if(s <= w &&  w <= t){
        ans++;
    }
    for(int i = 0;i < n-1;i++){
        cin >> a;
        w += a;
        if(s <= w &&  w <= t){
            ans++;
        }
    }

    cout << ans << endl; 
    
    return 0;
}
