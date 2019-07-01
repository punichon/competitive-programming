#include<iostream>
using namespace std;

int main(){

    int x,y,z,ans;
    cin >> x >> y >> z;
    int n = 1;
    ans = 0;
    while(ans <= x){
        ans = y*n+z*(n+1);
        if(ans > x){
            break;
        }
        n++;
    }

    cout << n-1 << endl;
    
    return 0;
}
