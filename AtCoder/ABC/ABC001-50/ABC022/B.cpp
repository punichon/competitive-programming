#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<map>
#include<queue>
#include<cstdio>
#include<cmath>

#define REP(n) for(int i = 0;i < n;i++)
#define LLREP(n) for(long long int  i = 0;i < n;i++)
typedef long long int ll;
using namespace std;
#define MAX_A 100005

int main(){

    int n;
    cin >> n;
    vector<int> a(MAX_A,0);
    vector<int> count(MAX_A,0);
    REP(n){
        cin >> a[i];
        count[a[i]]++;
    }
    /*REP(n){
        cout << count[i] << endl;
    }*/




    int ans = 0;
    REP(MAX_A){

        if(count[i]/2 > 0){
            ans+= count[i]-1;
        }
    }
    cout << ans << endl;

    return 0;
}
