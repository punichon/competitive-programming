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

    string s;
    string w;
    cin >> s;
    //cout << "w" << endl;

    REP(s.length()){
        //cout << "g" << endl;
        if(s[i] == '0'){
            w.push_back(s[i]);
        }
        if(s[i] == '1'){
            w.push_back(s[i]);
        }
        if(s[i] == 'B'){
            if(!w.empty()){
                //cout << "e" << endl;
                //cout << w << endl;
                w.pop_back();
                //cout << w << endl;
            }else{

            }
        }

    }
    cout << w << endl;

    return 0;
}
