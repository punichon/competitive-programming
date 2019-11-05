#include<iostream>
using namespace std;

int main(){

    int s,e,sum = 0;
    for(int i = 0;i < 3;i++){
        cin >> s >> e;
        //cout << s << " " << e << endl;;
        sum += s * e / 10;
    }
    cout << sum << endl;
    
    return 0;
}
