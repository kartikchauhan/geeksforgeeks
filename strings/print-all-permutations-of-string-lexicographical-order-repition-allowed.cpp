// print all permutations of a given string in lexicographical order with repetition of characters allowed.

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void printResult(vector<char> &result)
{
	int size = result.size();
	for(int i=0; i<size; i++)
		cout << result[i];
	cout << endl;
}

void getUniqueChars(map<char, int> &set, vector<char> &str, vector<int> &count)
{
	int size = set.size();
	int i = 0;
	for (map<char ,int>::iterator it = set.begin(); it != set.end(); it++)
	{
		str[i] = it->first;
		count[i] = it->second;
		i++;
	}
}

void permutations(vector<char> &str, vector<int> &count, vector<char> &result, int level)
{
	if(level == result.size())
	{
		printResult(result);
		return;
	}

	for(int i=0; i<str.size(); i++)
	{
		if(count[i] == 0)
			continue;
		else
		{
			result[level] = str[i];
			count[i]--;
			permutations(str, count, result, level+1);
			count[i]++;
		}
	}
}

int main()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    
    map<char, int> set;
    
    int sLength = s.length();
	    
    for(int i=0; i<sLength; i++)
    {
    	set[s[i]]++;
    }

    int setSize = set.size();

    vector<char> str(setSize), result(sLength);	// could've used setSize instead of str or count.
    vector<int> count(setSize);

    getUniqueChars(set, str, count);	// get all the distinct characters from the given string so that we could perform permutations on it.
    
    permutations(str, count, result, 0);
    return 0;
}