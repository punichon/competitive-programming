#include <iostream>
using namespace std;

int main() {
	// your code goes here

  int n = 0;
  cin >> n;

  if(n >= 0 && n < 60){
    cout << "Bad" << endl;
  }else if(n >= 60 && n < 90){
    cout << "Good" <<endl;
  }else if(n >= 90 && n < 100){
    cout << "Great" << endl;
  }else if( n == 100){
    cout << "Perfect" << endl;

  }
	return 0;
}
