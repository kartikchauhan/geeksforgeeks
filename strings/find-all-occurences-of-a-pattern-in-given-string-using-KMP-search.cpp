// Find all occurences of a pattern in a given string using KMP search algorithm.

#include <iostream>
#include <vector>

using namespace std;

vector<int> prefixSum(string pattern, int size)
{
	vector<int> prefixSumArr(size, 0);

	int i = 0, j = 1;

	while(j < size)
	{
		if(pattern[i] == pattern[j])
		{
			prefixSumArr[j] = i + 1;
			i++;
			j++;
		}
		else
		{
			if(i != 0)
				i = prefixSumArr[i-1];
			else
				j++;
		}
	}
	return prefixSumArr;
}

int main()
{
    string str, pattern;
    cin >> str;
    cin >> pattern;
    
    int patternSize = pattern.size();
    
    vector<int> prefixSumArr(patternSize, 0);
    prefixSumArr = prefixSum(pattern, patternSize);

    int strSize = str.size();

    int j = 0, i = 0;
    while(i < strSize)
    {
    	if(str[i] == pattern[j])
    	{
    		i++;
    		j++;
    	}
    	else
    	{
    		if(j != 0)
    			j = prefixSumArr[j-1];
    		else
    			i++;
    	}
    	if(j == patternSize)
    	{
    		cout << "Pattern found at " << (i-patternSize) << endl;
    	}
    }

    return 0;
}
// Input:
abxabcabcabcabcabc
abcabc