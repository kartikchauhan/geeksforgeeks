#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for(int i=0; i<(1 << n); i++)
    {
        vector<int> subSet;

        for(int j=0; j<n; j++)
        {
            if(i & (1<<j))
                subSet.push_back(j);
        }

        for(auto x: subSet)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}
