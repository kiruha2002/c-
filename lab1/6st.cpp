#include <iostream>

using namespace std;

int main()
    {
        int lenght_rect;
        cin >> lenght_rect;
        for (int i = 0; (2*i) < lenght_rect; i++)
        {
        for (int j = 0; j < i; j++ )
            {
                cout << ' ';
            }
        for (int j = lenght_rect - (2*i); j > 0; j--)
            cout <<'*';
        cout << ' ' << endl;
        }
    cin >> lenght_rect;

    return 0;
    }
