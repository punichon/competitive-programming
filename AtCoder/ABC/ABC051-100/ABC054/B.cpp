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
#define MAX_A 1000000007

int main(){

    int n,m;
    cin >> n >> m;

    char a[50][50];
    char b[50][50];
    bool exist = false;

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0;i < m;i++){
        for(int j = 0;j < m;j++){
            cin >> b[i][j];
        }
    }

    for(int i = 0;i < n-m+1;i++){
        for(int j = 0;j < n-m+1;j++){

            if(a[i][j] == b[0][0]){
                bool match = true;            
                for(int l = 0;l < m;l++){
                    for(int k = 0;k < m;k++){
                        if(a[i+l][j+k] != b[0+l][0+k]){
                            //cout << "b" << endl;
                            match = false;
                        }
                    }
                }
                if(match){
                    //cout << "a" << endl;
                    exist = true;
                }
            }
        }
    }

    if(exist){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }



    

    


    return 0;
}
