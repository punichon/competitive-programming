#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>

#define REP(n) for(int i = 0;i < n;i++)
typedef long long int ll;
using namespace std;
#define MAX_A 1000000005

int main(){


    string s,t,u;
    cin >> s >> t >> u;
    s[0] = char(s[0]-'a' + 'A');
    t[0] = char(t[0]-'a' + 'A');
    u[0] = char(u[0]-'a' + 'A');

    cout << s[0] << t[0] << u[0] << endl;



    return 0;
}
