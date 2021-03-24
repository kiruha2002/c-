#include <iostream>
#include <bitset>
using std::cin;
using std::cout;
using std::endl;
using std::bitset;


int main(){
	int a, b, c, d, x, mark;
	mark = 0;
	cin >> a >> b >> c >> d >> x;

	if (a + x == b or c * x == d){
		if (a + x == b and c * x == d){
			mark = 5;
		} else {
			mark = 4;
		}
	}


	if (mark == 0){
		if (x == 1024){
			mark = 3;
		} else {
			mark = 2;
		}
	}
	cout << mark << "\n";

return 0;
}
