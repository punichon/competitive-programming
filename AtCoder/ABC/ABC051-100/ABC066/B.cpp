#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long int ll;

int main(){

    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0;i < s.length()/2;i++){

        if(s.substr(0,i) == s.substr(i,i)){
            ans = 2*i;
        }
   }
   cout << ans << endl;


    return 0;
}
