#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int lenght_rect;

    cin >> lenght_rect;
    for (int i = 0; i <= lenght_rect; i++){
        for(int j = 0; j <= lenght_rect; j++){
    cout << '*';
    }
    cout << endl; }
    return 0;
}
