#include<iostream>
using namespace std;

int main(){

    int a,b,c;
    cin >> a >> b >> c;
    int choice = min(a,b);
    int ans = c / choice;
    cout << ans << endl;


    return 0;
}
