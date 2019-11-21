#include<iostream>
#include<vector>
using namespace std;
#define ARRAY_MAX 1000005

int main(){

    int n,a,b;
    cin >> n;
    vector<long long int> num(ARRAY_MAX,0); 
    for(int i = 0;i < n;i++){
        cin >> a >> b;
        num[a]++;
        num[b+1]--;
    }
    long long int maxi = -1000000;
    maxi = max(maxi,num[0]);
    for(int i = 1;i < ARRAY_MAX;i++){
        num[i] += num[i-1];
        maxi = max(maxi,num[i]);
    }
    cout << maxi << endl;


    return 0;
}
