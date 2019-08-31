#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>

#define REP(n) for(int i = 0;i < n;i++)
#define LLREP(n) for(long long int  i = 0;i < n;i++)
typedef long long int ll;
using namespace std;
#define MAX_A 1000000

int main(){

    int k,s;
    cin >> k >> s;
    vector<int> a(MAX_A,MAX_A);

    for(int i = k;i >= 0;i--){
        a[k-i] = s-i;
        //cout << a[i] << " ";
    }
    /*REP(k+1){
        cout << a[i];
    }
    cout << endl;*/
    int count = 0;
    //vector<int>::iterator itr;
    for(int i = 0;i <= k;i++){
        for(int j = 0;j <= k;j++){
            int tmp = i+j;
            //cout << i+j << endl;
            if(std::binary_search(a.begin(),a.end(),tmp)){
                count++;
                //cout << i+j << " " << count << endl;
            }

        }
    }
    cout << count << endl;


    return 0;
}
