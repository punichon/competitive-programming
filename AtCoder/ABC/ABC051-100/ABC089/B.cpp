#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cstdio>

#define REP(n) for(int i = 0;i < n;i++)
#define LLREP(n) for(long long int  i = 0;i < n;i++)
typedef long long int ll;
using namespace std;
#define MAX_A 1000000007

int main(){

   
    int n;
    cin >> n;

    char c;
    vector<bool> a(26,false);
    for(int i = 0;i < n;i++){
        cin >> c;
        a[c-'A']=true;
    }
    int count = 0;
    for(int i = 0;i < 26;i++){
        cin >> c;
        if(a[i] == true){
            count++;
        }
    }

    if(count == 3){
        cout << "Three" << endl;
    }else{
        cout << "Four" << endl;
    }


    return 0;
}
