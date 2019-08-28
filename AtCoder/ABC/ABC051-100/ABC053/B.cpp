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

    string s;
    cin >> s;
    //cout << s.length() << endl;

    int first = 0,last = 0;

    for(int i = 0;i < s.length();i++){

        if(s[i] == 'A'){
            first = i+1;
            break;
        }
    }


    for(int i = s.length();i >= 0;i--){

        if(s[i] == 'Z'){
            last = i+1;
            break;
        }
    }
    //cout << first << " " << last << endl;

    cout << last-first+1 << endl;
    return 0;
}
