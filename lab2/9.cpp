#include <iostream>
#include <string>


using namespace std;



int main() {
  int speed;
  int zp = 0;
  string Boss = "A999AA";
  string Nomer;
  cin >> speed;
  cin >> Nomer;
  while (Nomer != Boss)
    {
    if (speed > 60)
      {


        if ((Nomer[1] == Nomer[2]) and (Nomer[1] == Nomer[3]))
          {
          zp += 1000;
          }
      else
      if ((Nomer[1] == Nomer[2]) or (Nomer[1] == Nomer[3]) or (Nomer[2] == Nomer[3]))
        {
          zp += 500;
         }
      else
        {
          zp += 100;
        }
       }
      cin >> speed;
      cin >> Nomer;

      }
  cout << zp;

}
