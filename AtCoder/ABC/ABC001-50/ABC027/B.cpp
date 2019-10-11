#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<map>

#define REP(n) for(int i = 0;i < n;i++)
#define LLREP(n) for(long long int  i = 0;i < n;i++)
typedef long long int ll;
using namespace std;
#define MAX_A 100000

int main(){

    int n,sum=0,mean,ans=0;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n,0);
    REP(n){
        cin >> a[i];
        b[i]=a[i];
        sum+=a[i];
    }
    if(sum%n != 0){
        cout << "-1" << endl;
        return 0;
    }
    mean = sum/n;
    REP(n-1){
        b[i+1]+=b[i];
    }

    REP(n-1){

        if(b[i]==(i+1)*mean && (b[n-1]-b[i]) == (sum-(i+1)*mean)){

        }else{
            ans++;
        }

    }
    cout << ans << endl;



    

    return 0;
}
