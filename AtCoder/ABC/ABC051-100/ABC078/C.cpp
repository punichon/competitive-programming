#include<iostream>
using namespace std;


int main(){

    int n,m;
    cin >> n >> m;
    int case_1 = m;//1900ms
    int case_2 = n-m;//100ms

    int t_case2 = 100*case_2;
    long long int ans = (1900*m+100*(n-m));
    for(int i = 0;i < m;i++){
        ans*=2;
    }
    cout << ans << endl;
    
    




    return 0;
}
