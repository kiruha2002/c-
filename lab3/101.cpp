#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <set>
#include <numeric>
#include <functional>

using namespace std;



int main()
{
	int n;
	int sum = 0;
	cin >> n;

	vector<int> v;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	double mean = std::accumulate(v.begin(), v.end(), 0.0) / v.size();

	for (int a : v)
	{
		if (a > mean)
		{
			sum += a;
		}
	}

	cout << sum;

	return 0;
}
