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

    ll n,ans=1;
    cin >> n;

    vector<int> a(10000,0);

    for(int i = 2;i <= n;i++){//階乗のそれぞれ

        ll tmp = i;
        for(int j = 2;tmp > 1;j++){//何で割るか
            while(tmp%j == 0){//何回割れるか
                a[j]++;
                tmp/=j;
            }
        }
    }

    /*for(int i = 2;i <= n;i++){
        cout << a[i] << endl;
    }*/

    //cout << "a" << endl;
    for(int i = 2;i <= n;i++){
        //cout << a[i] << endl;

        ans = (ans*(a[i]+1))%MAX_A;
        //cout << ans << endl;

    }
    cout << ans << endl;

    return 0;
}
