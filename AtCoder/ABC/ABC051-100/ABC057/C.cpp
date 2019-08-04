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
#define MAX_A 1000000005

int main(){

    ll n,mini=MAX_A;
    cin >> n;

    for(ll i = 1;i*i <= n;i++){

        ll mod = n%i;
        ll ans = n/i;

        if(mod != 0){
            continue;
        }

        if(mod == 0){

            if(i > n/i){
                break;
            }

            string str_a,str_b;

            str_a = to_string(i);
            str_b = to_string(ans);

            ll mini_tmp = max(str_a.length(),str_b.length());
            //cout << mini_tmp << endl;
            mini = min(mini,mini_tmp);
        }
        //cout << mini << endl;
    }

    cout << mini << endl;




    return 0;
}
