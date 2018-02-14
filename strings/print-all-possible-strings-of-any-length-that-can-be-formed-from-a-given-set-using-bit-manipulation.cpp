// print all possible strings of any length that can be formed from a given set using bit manipulation

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.length();

    for(int i=0; i<(1 << n); i++)
    {
        string temp;

        for(int j=0; j<n; j++)
        {
            if(i & (1<<j))
                temp = temp + s[j];
        }

        cout << temp << endl;
    }

    return 0;
}