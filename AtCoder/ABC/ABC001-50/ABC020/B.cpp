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
#define MAX_A 105

int main(){

    string a,b;
    cin >> a >> b;
    string s = a+b;

    int n = stoi(s);

    cout << n*2 << endl;
 


    return 0;
}
