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

    int n,q,l,r,t;
    cin >> n >> q;
    vector<int> a(MAX_A,0);
    REP(q){

        cin >> l >> r >> t;
        for(int j = l-1;j < r;j++){
            a[j] = t;
        }            
    }

    REP(n){
        cout << a[i] << endl;
    }
    
    
    return 0;
}
