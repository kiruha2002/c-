#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double a, b;
    double c;
    cout << "insert legs:" << endl;
    cin >> a >> b;
    c = sqrt(pow(a, 2) + pow(b, 2));
    cout << "the hypotenuse is" << c ;
    return 0;
    }
