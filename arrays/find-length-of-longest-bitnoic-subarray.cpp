// find length of the longest bitonic subarray

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> input(n);

    for(int i=0; i<n; i++)
        cin >> input[i];

    vector<int> arrayLeftToRight(n, 1);
    vector<int> arrayRightToLeft(n, 1);

    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(input[j] < input[i])
            {
                arrayLeftToRight[i] = max(arrayLeftToRight[j]+1, arrayLeftToRight[i]);
            }
        }
    }   

    for(int i=n-2; i>=0; i--)
    {
        for(int j=n-1; j>i; j--)
        {
            if(input[j] < input[i])
            {
                arrayRightToLeft[i] = max(arrayRightToLeft[j]+1, arrayRightToLeft[i]);
            }
        }
    }

    int maxBitonicSequenceLength = 0;

    for(int i=0; i<n; i++)
    {
        int currVal = arrayLeftToRight[i] + arrayRightToLeft[i] - 1;

        if(currVal > maxBitonicSequenceLength)
            maxBitonicSequenceLength = currVal;
    }

    cout << maxBitonicSequenceLength << endl;

    return 0;
}
