#include<iostream>
#include<algorithm>
using namespace std;


int main(){

    int a,b;
    cin >> a >> b;
    int ans = 0;

    for(int i = a;i <= b;i++){
        //cout << i << endl;
        string s = to_string(i);
        //cout << s << endl;
        string t = s;
        reverse(t.begin(),t.end());
        if(s==t){
            ans++;
            //cout << s << " " << t << endl;
        }

    }
    
    cout << ans << endl;


    return 0;
}
