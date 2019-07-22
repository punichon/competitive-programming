#include <iostream>
#include<vector>
using namespace std;


int main(){


  int city = 0,road = 0;
  cin >> city >> road;

  vector<int> array1(128,0);
  vector<int> array2(128,0);

  for(int i = 0; i < road * 2;i++ ){
    cin >> array1[i];
  }

  for(int i = 0; i < road * 2;i++){
    array2[array1[i]]++;
  }


  for(int i = 1; i < city + 1;i++){

    //if(array2[i] == 0){
      //return 0;
    //}else{
      cout << array2[i] << endl;

    //}


}



  return 0;

}
