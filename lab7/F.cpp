#include <iostream>
#include <array>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::getline;

int* add_n(int numb[2002], int name){
	int i = 0;
	while (numb[i] != -1){
		i++;
	}
	numb[i] = name;
	return numb;
}

int* add_s(int numb[2002],int name){
	int len = 0;
	while (numb[len] != -1){
		len++;
	}
	int pos = (len + 1) / 2;
	for (int i = len - 1; i > pos - 1; i--){
		numb[i + 1] = numb[i];
	}
	numb[pos] = name;
	return numb;
}

int* move(int numb[2002]){
	int name = numb[0];
	for (int i = 0; i < 1000; i++){
		numb[i] = numb[i + 1];
	}
	int i = 2001;
	while (numb[i] != -1){
		i--;
	}
	numb[i] = name;
	return numb;
}


int main(){
	int *numb = new int[2002];
	for (int i = 0; i < 2002; i++){
		numb[i] = -1;
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		char a;
		int b;
		cin >> a;
		if (a != "-"[0]){
			cin >> b;
			if (a == "+"[0]){
				numb = add_n(numb, b);
			} else {
				numb = add_s(numb, b);
			}
		} else {
			numb = move(numb);
		}

	}
	int i = 2001;
	while (numb[i] != -1){
		cout << numb[i] << "\n";
		i--;
	}


return 0;
}
