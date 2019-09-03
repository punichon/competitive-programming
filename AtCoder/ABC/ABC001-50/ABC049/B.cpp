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

    int h,w;
    cin >> h >> w;
    vector<string> s(h);

    for(int i = 0;i < h;i++){
        cin >> s[i];
    }

    for(int i = 0;i < h;i++){
        cout << s[i] << endl;
        cout << s[i] << endl;
    }

    return 0;
}
