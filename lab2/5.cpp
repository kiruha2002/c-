#include <iostream>

using namespace std;

int main()
  {
  int a;
  int b = 0;
  cin >> a;
  while (a != 0)
  {
    if ((a % 2 == 0) and (b < a))
      {
      b = a;
      }
    cin >> a;
  }
  cout << b;
}
