#include<iostream>
#include<vector>
#include<algorithm>

#define REP(n) for(int i = 0;i < n;i++)
typedef long long int ll;
using namespace std;
#define MAX_A 100005

int main(){

    int a,b,c,tmp;
    cin >> a >> b >> c;
    //cout << a << b << c << endl;
    tmp = a;

    for(int i = 1;i < a*b;i++){
        if(a%b == c){
            cout << "YES" << endl;
            return 0;
        }else{
            a+=tmp;
            //cout << a << endl;
        }
    }
    cout << "NO" << endl;
    return 0;
}
