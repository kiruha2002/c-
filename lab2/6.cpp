#include <iostream>

using namespace std;

int main() {
  int a, N, M;
  N = 0;
  M = 0;
  while (true)
    {
    cin >> a;
    if (a == 0)

      {
      break;
      }

    if (a == M)
      {
      N++;
      }

    if (a > M)
      {
      M = a;
      N = 1;
      }
    }

  cout << N;
  return 0;
}
