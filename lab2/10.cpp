#include <iostream>


using namespace std;

void babylon(int chislo) {
  int temp;
  if (chislo / 60 != 0)
    {
    babylon(chislo / 60);
    }

  chislo = chislo % 60;
  for (int i = 0; i < (chislo / 10); i++)
    {
    cout << "<";
    }
  for (int i = 0; i < (chislo % 10); i++)
    {
    cout << "v";
    }
  cout << ".";
  }

int main() {
  int chislo;
  cin >> chislo;
  int temp;
  if (chislo / 60 != 0)
    {
    babylon(chislo / 60);
    }
  chislo = chislo % 60;
  for (int i = 0; i < (chislo / 10); i++)
    {
    cout << "<";
    }
  for (int i = 0; i < (chislo % 10); i++)
    {
    cout << "v";
  }
}
