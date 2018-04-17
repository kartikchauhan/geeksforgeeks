// check whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is same. Also print elements of the partitioned set.

#include <bits/stdc++.h>

using namespace std;

bool partition(vector<int> &input, vector<int> &output, int n, int sum, int &sumInpartition)
{
    if(sum == 0)
        return true;
    if(n == 0 and sum != 0)
        return false;

    if(input[n-1] > sum)
        return partition(input, output, n-1, sum, sumInpartition);

    bool result = (partition(input, output, n-1, sum, sumInpartition) || partition(input, output, n-1, sum-input[n-1], sumInpartition));
    if(result)
    {
        if(sumInpartition != sum)
        {            
            output.push_back(n-1);
            sumInpartition += input[n-1];
        }

        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> input(n);

    for(int i=0; i<n; i++)
        cin >> input[i];

    int sum = 0;

    for(int i=0; i<n; i++)
        sum += input[i];

    if(sum%2)
        cout << "Given set can't be partitioned in the desired way." << endl;
    else
    {
        vector<int> output;
        int sumInpartition = 0;
        bool result = partition(input, output, n, sum/2, sumInpartition);
        if(result)
        {
            cout << "Given set can be partitioned in the desired way." << endl;
            cout << "partitioned set " << endl;

            for(int i=0; i<output.size(); i++)
                cout << input[output[i]] << " ";            
        }
        else
        {            
            cout << "Given set can't be partitioned in the desired way." << endl;                
        }
    }

    return 0;
}