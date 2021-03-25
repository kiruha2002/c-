#include <iostream>

using namespace std;

int main()
  {
  int a, b;
cin >> a;
b = 0;
while (a != 0)
  {
  if (a % 2 == 0)
    {
    b++;
    }
  cin >> a;
  }
  cout << b << endl;
 }
