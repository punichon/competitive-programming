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

    int n,l;
    cin >> n >> l;
    vector<string> s(n);
    REP(n){
        cin >> s[i];
    }
    sort(s.begin(),s.end());

    REP(n){
        cout << s[i];
    }
    cout << endl;

    return 0;
}
