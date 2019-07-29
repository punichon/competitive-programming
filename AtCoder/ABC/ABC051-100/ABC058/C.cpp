#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
#define ARRAY_MAX 1005

int dp[ARRAY_MAX][ARRAY_MAX];
char alpha[29]= "abcdefghijklmnopqrstuvwxyz";


int main(){

    int n;
    cin >> n;
    string t;

    vector<string> s(n);
    
    vector<int> b(26,100000);
    for(int i = 0;i < n;i++){
        vector<int> a(26,0);
        cin >> t;
        for(int j = 0;j < t.length();j++){
            a[t[j]-'a']++;
        }
        
        for(int j = 0;j < 26 ;j++){
            b[j] = min(b[j],a[j]);
        }
        /*for(int j = 0;j < 26 ;j++){
            cout << b[j];
        }
        cout << endl;*/
    }

    for(int i = 0;i < 26;i++){
        for(int j = 0;j < b[i];j++){
            cout << alpha[i];
        }
    }
    cout << endl;

    

    


    return 0;
}
