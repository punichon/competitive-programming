#include <iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 3

int main() {
	
	int a,b,c;
	
	cin >> a >> b >> c;
	
	int sum1 = a+b;
	int sum2 = b+c;
	int sum3 = c+a;
	
	if(sum1 < sum2 && sum1 < sum3) cout << sum1 << endl;
	if(sum2 < sum1 && sum2 < sum3) cout << sum2 << endl;
	if(sum3 < sum2 && sum3 < sum1) cout << sum3 << endl;
	if(sum1 == sum2 && sum1 == sum3) cout << sum1 << endl;
		
	
	
	return 0;
}
