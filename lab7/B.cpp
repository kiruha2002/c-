#include <iostream>
#include <bitset>
#include <array>
using std::cin;
using std::cout;
using std::endl;
using std::bitset;

int main(){
	int n;
	cin >> n;
	int N[n];
	int bad[n];
    int nbad = 0;
	for (int i = 0; i<n; i++){
	cin >> N[i];
        if (((N[i] % 4 == 0) and (N[i] / 1000 != 4) and (N[i] / 1000 != 5)) or ((N[i] % 7 == 0) and (N[i] / 1000 != 7) and (N[i] / 1000 != 1)) or ((N[i] % 9 == 0) and (N[i] / 1000 != 9) and  (N[i] / 1000 != 8))){
            bad[nbad] = N[i];
			nbad++;
            }
        }
	for (int i = 0; i < nbad - 1; i++){
		cout << bad[i] << "\n";
    }
	if (nbad != 0){
		cout << bad[nbad - 1] << "\n";
		} else
		 {
		cout << "0\n";
	}

return 0;
}
