#include <iostream>
#include <array>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

using namespace std;

int main(){
	int n, truth, days, place, live, temp;
	cin >> n >> truth;
	string names[n];
	live = n;
	int state[n];
	for (int i = 0; i < n; i++){
		cin >> names[i] >> state[i];
	}
           cin >> days;
	place = 0;
	temp = truth;

	for (int d = 0; d < days; d++){
    int step = 1;
		if (live != 1){
			if (truth and state[place] == 0){temp = 0;}
            if (not truth and state[place] == 0){temp = 1;}
			if (state[place] == 1 and not truth){state[place] = -1; live--;}
			if (state[place] == 0 and not truth){state[place] = 1;}
            while (state[(place + step) % n] == -1){
				step += 1;
			}
			truth = temp;
			place = (place + step) % n;

            }
		}
    for (int i = 0; i < n; i++){
            if (state[i] != -1){
                cout << names[i] << " " << state[i] << "\n";
            }
        }


    return 0;
    }
