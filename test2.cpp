#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

#define lli long long int
using namespace std;


void minSwaps(vector<lli> num, vector< pair<lli, lli> > &swapsPeformed, lli &ans)
{
	lli n = num.size();

    pair<lli, lli> arrPos[n];
    for (lli i = 0; i < n; i++)
    {
        arrPos[i].first = num[i];
        arrPos[i].second = i;
    }
 
    sort(arrPos, arrPos + n);

    vector<bool> vis(n, false);
 
    for (lli i = 0; i < n; i++)
    {
        if (vis[i] || arrPos[i].second == i)
            continue;
 
        lli cycle_size = 0;
        lli j = i;
        while (!vis[j])
        {
            vis[j] = 1;

        	lli temp = j+1;
            j = arrPos[j].second;
            swapsPeformed.push_back(make_pair(temp, j+1));

            cycle_size++;
        }
 
        ans += (cycle_size - 1);
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	lli n;
	cin >> n;

	vector<lli> a(n);

	for(lli i=0; i<n; i++)
		cin >> a[i];
	
	lli swaps = 0;

	vector< pair<lli, lli> > swapsPeformed;

	minSwaps(a, swapsPeformed, swaps);

	cout << swaps << endl;
	
	for(lli i=0; i<swaps; i++)
		cout << swapsPeformed[i].first << " " << swapsPeformed[i].second << "\n";

	
    return 0;
}