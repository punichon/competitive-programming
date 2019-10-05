#include <iostream>
using namespace std;




int main() {


  int a,b,c,d;

  cin >> a;
  cin >> b;
  cin >> c;
  cin >> d;

  double n1 = (b / (double)a);
  double n2 = (d / (double)c);
  //cout >> n1 >> n2;

  if(n1 > n2){
    cout << "TAKAHASHI" << endl;
  }else if(n1 < n2){
    cout << "AOKI" << endl;
  }else if(n1 == n2){
    cout << "DRAW" << endl;
  }


	// your code goes here
	return 0;
}
