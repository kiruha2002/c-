#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int a;
  int i = 2;
  bool b;
  int c;
  cin >> a;
  while (a != 1)
    {
    c = floor(sqrt(a));
    i = 2;
    while (i <= c)
      {
      b = true;
      if (a % i == 0)
        {
        cout << i << endl;
        a = a / i;
        b = false;
        break;
        }
    i++;
    }
  if (b)
  {
  cout << a;
  a = 1;
  break;
  }
}


}
