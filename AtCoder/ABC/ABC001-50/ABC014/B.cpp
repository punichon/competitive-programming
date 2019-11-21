#include<iostream>
#include<vector>
using namespace std;
#define ARRAY_MAX 1000

int main(){

    int n,x,sum = 0;
    cin >> n >> x;
    vector<int> a(n);
    vector<int> num(ARRAY_MAX);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    int j = 0;
    while(x > 0){
        num[j] = x % 2;
        x /= 2;
        j++;
    }
    //num[j] = x;

    /*for(int i = j - 1;i >=0;i--){
        cout << num[i];
    }
    cout << endl;*/

    for(int i = j;i >=0;i--){
        if(num[i]){
            sum += a[i];
        }
    }
    cout << sum << endl;


    return 0;
}
