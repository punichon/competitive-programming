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

    ll n;
    cin >> n;
    string tmp;
    vector<ll> a(26,0);
    vector<bool> b(26,false);

    for(ll i = 0;i < n;i++){
        cin >> tmp;
        if(tmp[0] == 'M' || tmp[0] == 'A' || tmp[0] == 'R'|| tmp[0] == 'C' || tmp[0] == 'H'){
            a[tmp[0]-'A']++;
        }
        b[tmp[0]-'A'] = true;
    }
    ll count = 0;
    REP(26){
        if(b[i] == true){
            count++;
        }
    }

    /*REP(26){
        cout << a[i] << endl;
    }*/

    if(count < 3){
        cout << "0" << endl;
        return 0;
    }
    ll ans = 0;
    for(int i = 0;i < 26;i++){

        for(int j = i+1;j < 26;j++){

            for(int k = j+1;k < 26;k++){

            ans = ans + a[i]*a[j]*a[k];
            //cout << ans << endl;

            }
        }
        //cout << ans << endl;
    }

    cout << ans << endl;










    return 0;
}
