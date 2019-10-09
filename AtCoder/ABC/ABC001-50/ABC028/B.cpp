#include <iostream>
#include<cstdio>
using namespace std;

int main() {
	// your code goes here
  char str1[10] = {"ABCDEF"};
  char str2[100];
  int str3[6] = {0};

  cin >> str2;

  for(int i = 0; i < 100; i++){
  	if(str2[i] == '\0'){
  		break;
  	}
    if(str2[i] == 'A'){
      str3[0]++;
    }
    if(str2[i] == 'B'){
      str3[1]++;
    }
    if(str2[i] == 'C'){
      str3[2]++;
    }
    if(str2[i] == 'D'){
      str3[3]++;
    }
    if(str2[i] == 'E'){
      str3[4]++;
    }
    if(str2[i] == 'F'){
      str3[5]++;
    }
    
  }

  for(int i = 0; i < 5 ; i++){
    printf("%d ",str3[i]);
  }
  printf("%d\n",str3[5]);


  return 0;
}
