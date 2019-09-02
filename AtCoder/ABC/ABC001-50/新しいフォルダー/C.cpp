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
#define MAX_A 1000000
#define MOD 1000000007

int main(){

    int n,tmp;
    cin >> n;
    vector<int> a(MAX_A,0);

    REP(n){
        cin >> tmp;
        a[tmp]++;
    }
    /*REP(n){
        cout << a[i] << endl;
    }*/

    int ans = 1;
    bool exist = true;
    if(n%2 == 0){//偶数
        //cout << "a" << endl;
        for(int i = 1;i < n;i+=2){
            if(a[i]%2 != 0){
                //cout << "n" << endl;
                exist = false;
            }
        }
        if(exist){
            for(int i = 1;i < n;i+=2){
                ans = (ans*2)%MOD;
            }
        }
    }else{//奇数

        if(a[0]%2 != 1){
            exist = false;
        }
        for(int i = 2;i < n;i+=2){
            if(a[i]%2 != 0){
                exist = false;
            }
        }
        if(exist){
            for(int i = 2;i < n;i+=2){
                ans = (ans*2)%MOD;
            }
        }
    }

    if(exist){
        cout << ans << endl;
    }else{
        cout << "0" << endl;
    }






    return 0;
}
