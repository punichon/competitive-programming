#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<map>
#include<cstdio>
#include<cmath>

#define REP(n) for(int i = 0;i < n;i++)
#define LLREP(n) for(long long int  i = 0;i < n;i++)
typedef long long int ll;
using namespace std;
#define MAX_A 100000

int main(){

    int n,t,count = 0;
    cin >> n >> t;
    vector<int> a(n);
    REP(n){
        cin >> a[i];
    }

    REP(n-1){
        if(a[i+1]-a[i] >= t){
            count+= t;
        }else{
            count+=a[i+1]-a[i];
        }
        //cout << count << endl;
    }
    count+=t;
    cout << count << endl;
   


    return 0;
}
