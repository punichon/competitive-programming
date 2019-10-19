#include<iostream>
#include<algorithm>
using namespace std;

typedef long long int ll;

int main(){

    int n;
    cin >> n;
    int ans = (n/10) + (n%10);

    cout << ans << endl; 
    
    return 0;
}
