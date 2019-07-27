#include<iostream>
#include<vector>
#include<algorithm>

#define REP(n) for(int i = 0;i < n;i++)
typedef long long int ll;
using namespace std;
#define MAX_A 1000000005

int main(){

    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0;i < n;i++){
       cin >> a[i];
    }

    ll ans = 0;
    for(int i = 0;i < n;i++){

        if(i == n-1){
            ans+=k;
        }else{
            ans += min(k,a[i+1]-a[i]);
        }
        //cout << ans << endl;
    }
    cout << ans << endl;

    return 0;
}
