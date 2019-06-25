#include<iostream>
#include<vector>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> C(500);
    vector<int> S(500);
    vector<int> F(500);

    for(int i = 0;i < n-1;i++){
        cin >> C[i] >> S[i] >> F[i];
    }

    for(int i =0;i < n;i++){
        int t = 0;
        for(int j = i;j < n-1;j++){

            if(t < S[j]){
                t = S[j];
            }else if(t % F[j] == 0){

            }else{
                t = t + F[j] - t%F[j];
            }

            t += C[j];
        }
        cout << t << endl;
    }






    return 0;
}
