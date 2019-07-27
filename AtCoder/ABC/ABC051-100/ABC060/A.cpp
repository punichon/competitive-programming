#include<iostream>
#include<vector>
#include<algorithm>

#define REP(n) for(int i = 0;i < n;i++)
typedef long long int ll;
using namespace std;
#define MAX_A 100005

int main(){

    string a,b,c;
    cin >> a >> b >> c;

    if(a[a.length()-1] == b[0] && b[b.length()-1] == c[0]){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    
     
    return 0;
}
