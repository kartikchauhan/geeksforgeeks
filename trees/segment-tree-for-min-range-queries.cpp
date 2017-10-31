// creation of segment tree and find minimum with given query range. 
// Time complexities of various operations:
// Creation: O(n logn)
// findMin: O(n)


#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// utility functions

int nextPowerOf2(int n)
{
    int p = 1;
    if (n && !(n & (n - 1)))
        return n;
 
    while (p < n) 
        p <<= 1;
     
    return p;
}
 
int min(int first, int second)
{
	return first > second ? second : first;
}

void creation(vector<int> &segmentTreeArr, vector<int> &original, int low, int high, int pos)
{
	if(high == low)
	{
		segmentTreeArr[pos] = original[low];
		return;
	}

	int mid = (low + high)/2;
	creation(segmentTreeArr, original, low, mid, 2*pos+1);
	creation(segmentTreeArr, original, mid+1, high, 2*pos+2);

	segmentTreeArr[pos] = min(segmentTreeArr[2*pos+1], segmentTreeArr[2*pos+2]);
	return;
}

int findMin(vector<int> &segmentTreeArr, vector<int> &original, int qlow, int qhigh, int low, int high, int pos)
{
	if(low == high)
		return segmentTreeArr[pos];
	else if(qlow <= low && qhigh >= high)
		return segmentTreeArr[pos];
	else if(qlow > high || qhigh < low)
		return numeric_limits<int>::max();
	else
	{
		int mid = (low + high)/2;
		return( min( findMin(segmentTreeArr, original, qlow, qhigh, low, mid, 2*pos+1), findMin(segmentTreeArr, original, qlow, qhigh, mid+1, high, 2*pos+2)));
	}
	return 0;	// need to return because hackerrank's c++ compiler mandates it.
}

int main()
{
	int n, q;
    cin >> n >> q;
	vector<int> original(n);

	// taking input from the input stream
	for(int i=0; i<n; i++)
		cin >> original[i];

	// creating & initialisation of empty segment tree
	int segmentTreeSize = nextPowerOf2(n) * 2 - 1;  // getting smallest power of 2 greater than or equal to n
	int max = numeric_limits<int>::max();
	vector<int> segmentTreeArr(segmentTreeSize, max);

	creation(segmentTreeArr, original, 0, n-1, 0);

	// take queries from the input stream
	int start, end;
	for(int i=0; i<q; i++)
	{	
		cin >> start >> end;
		cout << findMin(segmentTreeArr, original, start, end, 0, n-1, 0) << endl;
	}

	return 0;
}
// Input:
4 2
-1 2 4 0
0 2
1 3