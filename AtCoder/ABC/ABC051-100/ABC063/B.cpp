#include<iostream>
#include<vector>
#include<algorithm>

#define REP(n) for(int i = 0;i < n;i++)
using namespace std;

int main(){

    string s;
    cin >> s;
    vector<bool> a(26,false);
    for(int i = 0;i < s.length();i++){
        if(a[s[i]-'a'] == true){
            cout << "no" << endl;
            return 0;
        }else{
            a[s[i]-'a'] = true;
        }
    }
    cout << "yes" << endl;

    
   
    return 0;
}
