#include<iostream>
using namespace std;

int main(){

    int n;
    cin >> n;
    int map[2][n];
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < n;j++){
            cin >> map[i][j];
        }
    }

    int ans = 0;
    for(int i = 0;i < n;i++){//はじめに右にi回進み、下に進み、その後全て右へ
        int tmp = 0;
        for(int j = 0;j <= i;j++){
            tmp += map[0][j];
        }
        tmp += map[1][i];
        for(int j = i+1;j < n;j++){
            tmp += map[1][j];
        }

        if(tmp > ans){
            ans = tmp;
        }
    }

    cout << ans << endl;


    return 0;
}
