#include <iostream>
#include <cmath>


using namespace std;


int main() {
  int a;
  int b = 1;
  int i = 2;
  int c;
  cin >> a;
  c= floor(sqrt(a));
  while (i <= c)
    {
    if (a % i == 0)
    {
      b = 0;
      break;
     }
  i++;
  }

cout << b;

}
� 2021 GitHub, Inc.
