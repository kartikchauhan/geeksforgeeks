// All possible strings of any length that can be formed from a given string

#include <bits/stdc++.h>

using namespace std;

void swap(string &s, int firstIndex, int secondIndex)
{
    char temp = s[firstIndex];
    s[firstIndex] = s[secondIndex];
    s[secondIndex] = temp;
}

int findCeil(string s, char ch, int startingIndex)
{
    int length = s.length();

    int ceilIndex;

    char smallest = numeric_limits<char>::max();

    for(int i = length-1; i >= startingIndex; i--)
    {
        if(s[i] > ch && s[i] < smallest)
        {
            smallest = s[i];
            ceilIndex = i;
        }
    }

    return ceilIndex;
}

void printPermutations(string s)
{
    int x = 1;

    int length = s.length();

    sort(s.begin(), s.end());

    bool isFinished = false;

    while(!isFinished)
    {
        x++;
        cout << s << endl;        

        int i = 0;

        // find the right most character which is smaller than its next.
        // Let's call this character targetChar
        for(i=length-2; i>=0; --i)
        {
            if(s[i] < s[i+1])
                break;
        }

        if(i == -1)
        {
            isFinished = true;
        }
        else
        {
            // ceil is the next smallest value which is greater than targetChar
            int ceilIndex = findCeil(s, s[i], i+1);

            swap(s, i, ceilIndex);

            sort(s.begin()+i+1, s.end());
        }
    }
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
 	
        printPermutations(subs);
    }
}
 
int main()
{
    string str;
    cin >> str;

    printCombinations(str);
    
    return 0;
}