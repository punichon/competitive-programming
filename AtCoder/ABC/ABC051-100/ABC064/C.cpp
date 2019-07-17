#include<iostream>
#include<vector>
#include<algorithm>

#define REP(n) for(int i = 0;i < n;i++)
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<bool> a(12,0);
    int tmp = 0;
    int count = 0;
    REP(n){
        cin >> tmp;
        if(tmp >=3200){
            count++;
        }
        a[tmp/400] = true;
    }

    int color_count = 0;
    REP(8){
        if(a[i] == true){
            color_count++;
        }
    }

    int mini = (color_count != 0) ? color_count : 1;
    int maxi = color_count+count;

    cout << mini << " " << maxi << endl;


    
   
    return 0;
}
