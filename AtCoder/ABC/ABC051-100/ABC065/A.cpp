#include <iostream>
using namespace std;

int main() {
	
	long long int limit = 0;
	long long int x,a,b;
	cin >> x >> a >> b;

	if(b-a <= 0)  cout << "delicious" << endl;
	if(b-a > 0 && b-a <= x) cout << "safe" << endl;
	if(b-a > 0 && b-a >= x+1) cout << "dangerous" << endl;
	
	
	
	
	return 0;
}
