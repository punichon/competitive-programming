#include<iostream>
#include<cmath>
using namespace std;

int main(){

    double w,a,b,ans;

    cin >> w >> a >> b;

    if(a+w>=b && b+w >= a){
        ans = 0;
    }else{
        ans = min(fabs(b-a-w),fabs(b+w-a));
    }
    
    cout << int(ans) << endl;

    return 0;
}
