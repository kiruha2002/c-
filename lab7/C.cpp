#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

double round3(double f, int *num)
{
int64_t i, n = 1;

i = round(f*1000);
if (i % 100)
n++;
if (i % 10)
n++;
f = i / 1000.0;

if (num)
*num = n;
return f;
}

int main(){
	vector<int> data(0);
	vector<int> data2(0);
	long long int sum = 0, sum2 = 0;
	double mean, mean2;
	int temp = 1;
	int i = 0;
	while (temp != 0){
		cin >> temp;
		if (temp != 0){
			data.push_back(temp);
			sum += data[i];
			data2.push_back(data[i] * data[i]);
			sum2 += data2[i];
			i++;
		}
	}
	mean = ((double) sum / i);
	mean2 = ((double) sum2 / i);
	int n = 0;
	double t = mean2 - mean * mean;
	mean = round3(mean, &n);
	cout << fixed << setprecision(n) << mean << " ";
	t = round3(t, &n);
	cout << fixed << setprecision(n) << t << endl;

return 0;
}
