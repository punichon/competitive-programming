#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>

#define REP(n) for(int i = 0;i < n;i++)
#define LLREP(n) for(long long int  i = 0;i < n;i++)
typedef long long int ll;
using namespace std;
#define MAX_A 1000000005

int main(){

    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(m);
    vector<int> d(m);


    REP(n){
        cin >> a[i] >> b[i];
    }

    REP(m){
        cin >> c[i] >> d[i];
    }

    for(int i = 0;i < n;i++){
        int flag = 1000000000;
        int ans = 1000000000;
        for(int j = 0;j < m;j++){
            //cout << "flag=" << flag <<  endl;
            

            int tmp = abs(a[i]-c[j])+abs(b[i]-d[j]);
            //cout << "tmp=" << tmp << endl;

            //cout << "j=" << j << endl;
            if(ans >= tmp){
                //cout << "ans=" << ans << endl;
                //cout << "tmp=" << tmp << endl;
                if(ans > tmp){

                    ans = tmp;
                    flag = j+1;

                }else{
                    flag = min(flag,j+1);
                }


            }
            
            
            //cout << "ans=" << ans << endl;
            //cout << "flag=" << flag << endl;
        }
        cout << flag << endl;
        flag = 1000000000;
        ans = 1000000000;
    }
    return 0;
}
