#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 999999999
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;

int main(){


    string s1,s2;
    cin >> s1 >> s2;
    //cout << s1 << s2 << endl;
    int tmp = s1.length();

    vector<int> a(s1.length()),b(s2.length());

    for(int i = 0;i < s1.length()-1;i++){
        a[i]=s1[i+1]-s1[i];
    }
    a[s1.length()-1]=s1[0]-s1[s1.length()-1];
    for(int i = 0;i < s2.length()-1;i++){
        b[i]=s2[i+1]-s2[i];
    }
    b[s1.length()-1]=s2[0]-s2[s1.length()-1];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    
    for(int i = 0;i < s1.length();i++){
        if(a[i] != b[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
