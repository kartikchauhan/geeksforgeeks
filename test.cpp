#include <bits/stdc++.h>
#define lli long int
#define mod 1000000007

using namespace std;

void printAll(vector<lli> &storage, string str, lli &maxLengthPalindrome)
{
    lli n = str.length();
    unsigned lli opsize = pow(2, n);
 
    for (lli counter = 1; counter < opsize; counter++)
    {
        string subs = "";
        for (lli j = 0; j < n; j++)
        {
            /* Check if jth bit in the counter is set
                If set then print jth element from arr[] */
            if (counter & (1<<j))
                subs.push_back(str[j]);
        }
 
        /* Print all permutations of current subsequence */
        do
        {
            lli length = subs.length();
            lli flag = true;

            for(lli k=0; k<length; k++)
            {
                if(subs[k] != subs[length-k-1])
                {
                    flag = false;
                    break;
                }
            }
            if(flag == true)
            {
                storage[length] = (storage[length] % mod) + (1 % mod);

                if(length > maxLengthPalindrome)
                {
                    maxLengthPalindrome = length;
                }                
            }
        }
        while (next_permutation(subs.begin(), subs.end()));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;

    lli stringLength = s.length();

    lli q;
    cin >> q;

    lli l, r;
    while(q--)
    {
        cin >> l >> r;
        
        vector<lli> storage(stringLength);
        lli maxLengthPalindrome = 0;
        string subString = s.substr(l-1, r-l+1);

        printAll(storage, subString, maxLengthPalindrome);

        cout << storage[maxLengthPalindrome] << endl;
    }
    
    return 0;
}
