#include <iostream>
#include <array>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using namespace std;


     int main(){
	int n;
	cin >> n;
	int in[n][n];
	int out[n][n];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> in[i][j];
			out[j][n - i - 1] = in[i][j];
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << out[i][j] << " ";
		}
		cout << "\n";
	}

return 0;
}
