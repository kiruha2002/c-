#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

vector<int> split(string line){
	vector<int> words(0);
	stringstream s(line);
	int word;
	int i = 0;
	while (s >> word){
		words.push_back(word);
		i++;
	}
	words.insert(words.begin(), i);
	return words;

}

void step(vector<int> num, vector<int> init, int *n){
	int a = 0;
	int i;
	for (i = 0; i < *n; i++){
		a = max(a, num[i]);
	}
	if (a != 0){
		vector<int> ones;
		vector<int> zeros;
		int nz = 0, no = 0;
		vector<int> temp_init = init;
		vector<int> temp_num = num;
		for (i = 0; i < *n; i++){
			if (num[i] % 10 == 0){
				zeros.push_back(i);
				nz++;
			} else {
				ones.push_back(i);
				no++;
			}
		}
		for (i = 0; i < nz; i++){
			temp_num[i] = num[zeros[i]];
			temp_init[i] = init[zeros[i]];
		}
		for (; i < *n; i++){
			temp_num[i] = num[ones[i - nz]];
			temp_init[i] = init[ones[i - nz]];
		}
		init = temp_init;
		num = temp_num;
		for (i = 0; i < *n; i++){
			cout << init[i] << " ";
			num[i] = num[i] / 10;
		}
		cout << "\n";
		step(num, init, n);
		return;
	}
return;
}

int main(){
	string line;
	std::getline(cin, line);
	vector<int> init = split(line);
	vector<int> a(init[0]);
	vector<int> b(init[0]);
	for (int i = 0; i < init[0]; i++){
		a[i] = init[i + 1];
		b[i] = init[i + 1];
	}
	int n = init[0];
	step(a, b, &n);



return 0;
}
