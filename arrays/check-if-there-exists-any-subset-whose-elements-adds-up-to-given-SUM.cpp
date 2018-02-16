// check if there exists any subset whose elements adds up to given SUM

// The idea to check whether to take an element or not. Starting from the last element of the given array, if the element is found to be
// smaller than SUM then it'll be taken into consideration once and will be passed on in other case.

#include <bits/stdc++.h>

using namespace std;

bool subSetExists(vector<int> &inputArray, int sum, int n)
{
    if(sum == 0)
        return true;

    if(sum != 0 && n == 0)
        return false;

    if(inputArray[n-1] > sum)   
        return subSetExists(inputArray, sum, n-1);

    return (subSetExists(inputArray, sum, n-1) || subSetExists(inputArray, sum - inputArray[n-1], n-1));
}

int main()
{
    int n;
    cin >> n;

    vector<int> inputArray(n);

    for(int i=0; i<n; i++)
        cin >> inputArray[i];

    int sum;
    cin >> sum;

    if(subSetExists(inputArray, sum, n))
        cout << "There exists a subset whose elements adds up to give " << sum << endl;
    else
        cout << "There doesn't exists any subset whose elements adds up to give " << sum << endl;



    return 0;
}