#include<iostream>
#include<algorithm>
using namespace std;

typedef long long int ll;

int main(){

    int a,b,c,k,s,t,ans;
    cin >> a >> b >> c >> k;
    cin >> s >> t;

    if(s+t >= k){
        ans = a*s+b*t-c*(s+t);
    }else{
        ans = a*s+b*t;
    }
    cout << ans << endl;
    
    return 0;
}
