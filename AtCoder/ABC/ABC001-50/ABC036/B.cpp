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

    int n;
    cin >> n;
    char s[n][n];
    char ans[n][n];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> s[i][j]; 
        }
    }

    for(int i = 0;i < n;i++){
        for(int j = n-1;j >= 0;j--){

            cout << s[j][i];
        
        }
        cout << endl;
    }
    
    
    return 0;
}
