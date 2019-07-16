#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<deque>
using namespace std;
typedef long long int ll;

#define MAX_A 1000000

int main(){

    int n;
    cin >> n;
    vector<int> a(MAX_A,0);
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }

    int button = 1;
    for(int i = 1;i <= n;i++){

        if(button == 2){
            cout << i-1 << endl;
            return 0;
        }
        button = a[button];

    }

    cout << "-1" << endl;



    return 0;

}
