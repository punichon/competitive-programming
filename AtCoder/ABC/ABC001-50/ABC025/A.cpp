#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long int ll;

int main(){

    string s;
    cin >> s;
    int n;
    cin >> n;
    int a = (n-1) / 5;
    int b = (n-1) % 5;
    cout << s[a] << s[b] << endl;

    
    return 0;
}
