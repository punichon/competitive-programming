#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>

#define REP(n) for(int i = 0;i < n;i++)
#define LLREP(n) for(long long int  i = 0;i < n;i++)
typedef long long int ll;
using namespace std;
#define MAX_A 100005

int main(){

    int n,m,x,left=0,right=0;
    cin >> n >> m >> x;
    vector<int> array(m);
    for(int i = 0;i < m;i++){
        cin >> array[i];
        if(array[i]< x){
            left++;
        }else{
            right++;
        }
    }
    cout << min(left,right) << endl;



   
    return 0;
}
