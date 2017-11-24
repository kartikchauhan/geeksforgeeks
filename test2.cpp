#include <iostream>
#include <vector>
#include <algorithm>
#define lli long long unsigned int
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<lli> num(n);

	for(int i=0; i<n; i++)
		cin >> num[i];

	vector<lli> subset;

	for(int i=0; i<n; i++)
	{
    	lli xorValue;

		for(lli j=i; j<n; j++)
		{
			if(i == j)
				subset.push_back(num[i]);
			else if(j == i+1)
			{
				xorValue = num[i] xor num[j];
				subset.push_back(xorValue);
			}
			else
			{
				xorValue = subset.back() xor num[j];
				subset.push_back(xorValue);
			}
			
		}
	}

	sort(subset.begin(), subset.end(), greater<lli>());
	
	lli subsetsSize = subset.size();

	cout << subset[k-1];
    
    return 0;
}