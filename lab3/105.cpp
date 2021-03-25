#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int *c = &a;
	int *d = &b;
	cout << do_some_awesome_work(c, d) << endl;
	return 0;
}
