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

    int n,area,dif,mod;
    int ans = 100000000;
    cin >> n;
    for(int i = 1;i*i<=n;i++){

        int tmp = n/i;
        area = i*tmp;
        mod = n-area;
        ans = min(ans,abs(i-tmp)+mod);
    }
    cout << ans << endl;

    return 0;
}
