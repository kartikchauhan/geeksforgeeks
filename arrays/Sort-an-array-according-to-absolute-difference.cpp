// Sort an array according to absolute difference with given value. 
// We're using multimaps in this question to achieve the purpose.
// Multimaps are used to store key value pairs. They are different from map data structure because they can store two elements with same key.
// Multimaps make use of self-balancing binary search tree and give results in sorted order.

// The question can also be solved by sorting the array using any stable sort algorithm.
// Instead of comparing elements, we'll have to compare the absolute difference from given value to sort the array.

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> input(n);

    for(int i=0; i<n; i++)
        cin >> input[i];

    multimap<int, int> mulMap;

    for(int i=0; i<n; i++)
        mulMap.insert(make_pair(abs(k - input[i]), input[i]));

    multimap<int, int>::iterator it;

    for(it = mulMap.begin(); it != mulMap.end(); ++it)
        cout << it->second << " ";

    return 0;
}