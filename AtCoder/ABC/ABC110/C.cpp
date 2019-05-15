#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include <numeric>
#include<map>


#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 999999999
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;

typedef long long int ll;


int main(){

    string s1,s2;
    cin >> s1 >> s2;

    string s = "abcdefghijklmnopqrstuvwxyz";
    vector<int> a(26,0),b(26,0); 
    vector<bool> used_a(26,false),used_b(26,false);

    REP(i,s1.length()){
        a[s1[i] - 'a']++;
    }

    REP(i,s2.length()){
        b[s2[i] - 'a']++;
    }

    bool can = true;

    int count_a = 0,count_b = 0;

    REP(i,26){
        if(a[i] != 0){
            count_a++;
        }
    }

   

    REP(i,26){
        if(b[i] != 0){
            count_b++;
        }
    }

    

    for(int i = 0;i < 26;i++){

        if(a[i] == 0){
            continue;
        }
        for(int j = 0;j < 26;j++){
            if(b[j] == 0){
                continue;
            }else if(a[i] == b[j] && used_a[i] == false && used_b[j] == false){

                count_a--;
                count_b--;
                used_a[i] = true;
                used_b[j] = true;
                break;
            }
        }
    }

    if(count_a == 0 && count_b == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }



    return 0;
}
