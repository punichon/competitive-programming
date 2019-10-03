#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<map>

#define REP(n) for(int i = 0;i < n;i++)
#define LLREP(n) for(long long int  i = 0;i < n;i++)
typedef long long int ll;
using namespace std;
#define MAX_A 100000

int main(){

    string s;
    int n,count = 0;
    cin >> s >> n;
    //cout << s << endl;

    if(s.length()<n){
        cout << "0" << endl;
        return 0;
    }


    map<string,int> mp;

    map<string,int>::iterator itr;

    for(int i = 0;i < s.length()-n+1;i++){
        //cout << i << endl;
        string tmp;
        for(int j = i;j < n+i;j++){
            //cout << "j=" << j << endl;
            //cout << s[j] << s[j+1] << endl;
            tmp.push_back(s[j]);
        }
        //cout << tmp << endl;
        mp[tmp]++;
    }

    int ans = 0;
    for(itr = mp.begin(); itr != mp.end(); itr++) {

        ans++;
        mp.erase(itr);
    }
    
    cout << ans << endl;







    return 0;
}
