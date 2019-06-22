#include<iostream>
using namespace std;

int main(){

    long long int n,Y;
    cin >> n >> Y;
    //cout << Y << endl;

    for(int x =0;x <= n;x++){
        for(int y = 0;y <= n;y++){

            int z = n-x-y;
            //cout << z << endl;
            if(z < 0){
                
            }else{
                long long int sum = 10000*x+5000*y+1000*z;
                //cout << z << " " << sum <<endl;
                if(sum == Y){
                    cout << x << " " << y << " " << z << endl;
                    return 0;
                }
            }
        }
    }

    cout << "-1 -1 -1" << endl;

    return 0;
}
