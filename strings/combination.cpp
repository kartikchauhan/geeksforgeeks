#include <bits/stdc++.h>

using namespace std;

void printPermutationsUtil(string &set, string prefix, int outputLength, int length)
{
	if(outputLength == 0)
	{
		cout << prefix << endl;
		return;
	}

	for(int i=0; i<length; i++)
	{
		string newPrefix = prefix + set[i];
		printPermutationsUtil(set, newPrefix, outputLength-1, length);
	}

}

void printPermutations(string &set, int outputLength)
{
	int length = set.length();

	printPermutationsUtil(set, "", outputLength, length);
}

void printCombinations(string str)
{
    int n = str.length();
    int opsize = pow(2, n);
 
    for (int counter = 1; counter < opsize; counter++)
    {
        string subs = "";
        for (int j = 0; j < n; j++)
        {
            if (counter & (1<<j))
            {
                subs.push_back(str[j]);
            }
        }
 	
        printPermutations(subs, subs.length());
    }
}
 
int main()
{
    string str = "abc";
    printCombinations(str);
    return 0;
}