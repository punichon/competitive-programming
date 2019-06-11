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

    string s;
    cin >> s;
    int count = 0;
    for(int i = 0;i < 3;i++){
        if(s[i] == 'o'){
            count++;
        }
    }
    cout << 700+count*100 << endl;

    return 0;
}
