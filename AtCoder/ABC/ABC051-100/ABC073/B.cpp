#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;


int main(){

    int N,l,r,count = 0;;
    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> l >> r;
        count += (r-l+1);

    }

    cout << count << endl;
    return 0;
}
