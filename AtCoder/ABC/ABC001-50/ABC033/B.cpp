#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<map>

#define REP(n) for(int i = 0;i < n;i++)
#define LLREP(n) for(long long int  i = 0;i < n;i++)
typedef long long int ll;
using namespace std;
#define MAX_A 100000

int main(){

    ll n,population=0;
    cin >> n;
    ll num;
    string s,ans_name;
    vector< pair<string,ll> > a(n);
    for(int i = 0;i < n;i++){
        cin >> s >> num;
        //pair<string,int> tmp_pair = 
        a[i] = make_pair(s,num);
        population+=num;
    }
    for(int i = 0;i < n;i++){

        if(a[i].second*2 > population){
            ans_name = a[i].first;
            cout << ans_name << endl;
            return 0;
        }
    }
    cout << "atcoder" << endl;





    return 0;
}
