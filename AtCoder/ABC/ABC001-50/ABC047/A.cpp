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
#define MAX_A 1000000007

int main(){

    int a,b,c;
    cin >> a >> b >> c;

    int maxi = max(a,max(b,c));
    int mini = min(a,min(b,c));
    int middle = a+b+c-maxi-mini;
    if(mini+middle == maxi){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}
