// check if there exists any subset whose elements adds up to given SUM and if it does then print its elements.

// Here dynamic approach is used.
// For more info: https://www.youtube.com/watch?v=s6FhG--P7z0

#include <bits/stdc++.h>

using namespace std;

void printPath(vector< vector<bool> > &subset, vector<int> set, int row, int col)
{
    if(row == 0)
    {
        if(subset[row][col])
            cout << set[row] << endl;
        return;
    }

    if(subset[row-1][col])
    {
        printPath(subset, set, row-1, col);
    }
    else
    {
        cout << set[row] << " ";
        col = col - set[row];
        row = row-1;
        printPath(subset, set, row, col);
    }
}

void findSubSet(vector<int> &set, vector< vector<bool> > &subset, int sum, int n)
{
    for(int i=0; i<n; i++)
        subset[i][0] = true;

    for(int i=0; i<n; i++)
    {
        for(int j=1; j<=sum; j++)
        {
            if(i == 0)
            {
                if(j == set[i])
                    subset[i][j] = true;
                else
                    subset[i][j] = false;
            }
            else
            {
                if(subset[i-1][j])
                    subset[i][j] = true;
                else if(j < set[i])
                    subset[i][j] = subset[i-1][j];
                else if(j == set[i])
                    subset[i][j] = true;
                else
                    subset[i][j] = subset[i-1][j-set[i]];
            }
        }
    }

    // print subset

    // for(int i=0; i<=sum; i++)
    //     cout << i << " ";
    // cout << endl;

    // for(int i=0; i<n; i++)
    // {
    //     for(int j=0; j<=sum; j++)
    //         cout << subset[i][j] << " ";
    //     cout << endl;
    // }

    // cout << endl;
}

int main()
{
    int n;
    cin >> n;

    vector<int> set(n);

    for(int i=0; i<n; i++)
        cin >> set[i];

    int sum;
    cin >> sum;

    vector< vector<bool> > subset(n, vector<bool>(sum+1));
    
    findSubSet(set, subset, sum, n);

    if(!subset[n-1][sum])
        cout << "No such subset exists" << endl;
    else
    {
        printPath(subset, set, n-1, sum);        
    }

    return 0;
}