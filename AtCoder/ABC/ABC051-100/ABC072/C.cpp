#include<iostream>
#include<vector>
using namespace std;
#define ARRAY_MAX 100001 

int main(){

    
    int N,hoge,num_max = 0,ans = 0,sum = 0;
    cin >> N;


    vector<int> count(ARRAY_MAX,0);
    while(N > 0){
        cin >> hoge;
        count[hoge]++;
        count[hoge+1]++;
        if(hoge > 0){
            count[hoge-1]++;
        }else{
            sum++;
        }
            
        if(num_max < hoge){
            num_max = hoge;
        }
        N--;
    }
    for(int i = 0;i < num_max;i++){
        if(ans < count[i]){
            ans = count[i];
        }
    }
    if(ans < sum){
        ans = sum;
    }

    cout << ans << endl;

    return 0;
}
