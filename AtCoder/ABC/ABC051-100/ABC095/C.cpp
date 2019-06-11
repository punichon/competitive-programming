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

    ll a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    //cout << a << b << c << x << y << endl;

    ll ans1 = a*x+b*y;
    ll ans2 = 1000000000000000;
    ll ans3 = 1000000000000000;
    ll ans4 = 1000000000000000;
    if(x>y){
        ans2 = min(2*c*y + (x-y)*a,2*c*x);
    }else if(x<y){
        ans3 = min(2*c*x+(y-x)*b,2*c*y);
    }else{
        ans4 = min(2*c*y,2*c*x);
    }
    //cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << endl;
    ll ans = min(min(ans1,ans2),min(ans3,ans4));
    cout << ans << endl;
    
    return 0;
}
