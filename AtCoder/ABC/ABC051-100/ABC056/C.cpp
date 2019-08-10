#include<iostream>
using namespace std;

int main(){


    long long int x;
    cin >> x;
    //bool flag = true;
    long long int i = 1;
    long long int ans = 0;
    while(1){
        long long int tmp = 1+(i-1)*(i+2)/2;
        if(tmp >= x){
            //flag = false;
            ans = i;
            break;
        }
        i++;
    }

    cout << ans << endl;

    return 0;
}
