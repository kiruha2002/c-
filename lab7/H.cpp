#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int find_pair(int n, int *tap){
	int mind = n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (tap[i] == -tap[j] and abs(i - j) < mind and (i - j) * (tap[i] - tap[j]) > 0){
				mind = abs(i - j);
			}
		}
	}
	if (mind == n){mind = 0;}
	return mind;
}

int main(){
	int n;
	cin >> n;
	int tap[n];
	for (int i = 0; i < n; i++){
		cin >> tap[i];
	}
	int mind = find_pair(n, tap);
	cout << mind << "\n";
return 0;
}
