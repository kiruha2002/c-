#include <iostream>

using namespace std;


int main()
  {
  int a;
  bool b = true;
  cin >> a;
  while (a % 2 == 0)
    {
    a = a / 2;
    }
  if ((a==1))
    {
    cout << "YES" << ;
    }
  else
    {
    cout << "NO" << endl;
    }
}
