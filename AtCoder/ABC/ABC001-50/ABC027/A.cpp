#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	
	std::vector<int> array(4);
	int n = 0;
	
	for(int i = 0; i < 3 ; i++){
		cin >> array[i];
	}
	
	sort(array.begin(),array.end());
	
	if(array[1] == array[2]){
		n = array[3];
	}
	
	if(array[2] == array[3]){
		n = array[1];
	}
	
	cout << n << endl;
	// your code goes here
	return 0;
}
