#include <iostream>
using namespace std;

int main()
  {
  int a, b, c;
  cin >> a;
  cin >> b;
  if (b > a)
  {
  c = a;
  a = b;
  b = c;
  }
  while (a * b != 0)
  {
  a = a % b;
  if (a != 0)
    {
    b = b % a;
    }
  }
  if (a!= 0)
    {
      cout << a << endl;
    }
  else
    {
    cout << b << endl;
    }
  }
