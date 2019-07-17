#include<iostream>
#include<vector>
#include<algorithm>

#define REP(n) for(int i = 0;i < n;i++)
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    
    REP(n){
        cin >> a[i];
    }
    sort(a.begin(),a.end());

    cout << a[n-1]-a[0] << endl;
   
    return 0;
}
