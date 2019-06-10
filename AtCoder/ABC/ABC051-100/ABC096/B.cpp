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

    int k;
    vector<int> a(3);
    REP(3){
        cin >> a[i];
    }
    cin >> k;

    sort(a.begin(),a.end());

    cout << a[0]+a[1]+a[2]*pow(2,k) << endl;

    
   
    return 0;
}
