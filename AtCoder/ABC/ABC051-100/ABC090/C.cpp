#include<iostream>
#include<algorithm>
using namespace std;

typedef long long int ll;

int main(){

    ll n,m,ans=0;
    cin >> n >> m;
    if(n>m){
        swap(n,m);
    }

    if(n == 1){

        if(m == 1){
            ans = 1;
        }else{
            ans = m-2;
        }
    }else{
        ans = (n-2)*(m-2);
    }

    cout << ans << endl;
   
    


    return 0;
}
