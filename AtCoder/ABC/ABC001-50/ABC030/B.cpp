#include <iostream>
#include<cmath>
using namespace std;




int main() {

  int n,m;
  cin >> n;
  cin >> m;

  if(n > 12){
    n = n-12;
  }

  double n1 = 6.0 * m;//長針
  double n2 = 30.0 * n+ 0.5 * m;//短針


  

  double argu1 = abs(n1 - n2);

  

  if(argu1 > 180.0){
    argu1 = 360.0-argu1;
  }

  printf("%.5f\n",argu1);





  return 0;

}
