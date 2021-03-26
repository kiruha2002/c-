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

int main(){
	string line;
	std::getline(cin, line);
	vector<int> num = split(line);
	vector<int> ev_num(1, 0);
	vector<int> un_num(1, 0);
	for (int i = 1; i <= num[0]; i++){
		if (num[i] % 2 == 0){
			ev_num[0]++;
			ev_num.push_back(num[i]);
		} else {
			un_num[0]++;
			un_num.push_back(num[i]);
		}
	}
	sort(ev_num.begin() + 1, ev_num.end());
	sort(un_num.begin() + 1, un_num.end());
	for (int i = 1; i <= ev_num[0]; i++){
		cout << ev_num[i] << " ";
	}
	for (int i = 1; i <= un_num[0]; i++){
		cout << un_num[i] << " ";
	}
	cout << "\n";



return 0;
}
