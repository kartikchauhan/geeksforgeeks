#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#define lli long int

using namespace std;

lli nextPowerOf2(lli n)
{
    lli p = 1;
    if (n && !(n & (n - 1)))
        return n;
 
    while (p < n) 
        p <<= 1;
     
    return p;
}

lli max(lli first, lli second)
{
    return first > second ? first : second;
}

void get_bounds(vector<lli> &xPos, lli lbTarget, lli ubTarget, lli &lb, lli &ub, lli n)
{
    for(lli i=0; i<n; i++)
    {
        if(xPos[i] >= lbTarget)
        {
            if(lb == -1)
                lb = i;
        }
        if(xPos[i] == ubTarget)
        {
            if(ub == -1)
                ub = i;
        }
        else if(xPos[i] > ubTarget)
        {
            if(ub == -1)
                ub = i-1;
        }
    }
    if(ub == -1)
    {
        ub = n-1;
    }
}

void creation(vector<lli> &segmentTreeArr, vector<lli> &original, lli low, lli high, lli pos)
{
    if(high == low)
    {
        segmentTreeArr[pos] = original[low];
        return;
    }

    lli mid = (low + high)/2;
    creation(segmentTreeArr, original, low, mid, 2*pos+1);
    creation(segmentTreeArr, original, mid+1, high, 2*pos+2);

    segmentTreeArr[pos] = max(segmentTreeArr[2*pos+1], segmentTreeArr[2*pos+2]);
    return;
}

lli findMax(vector<lli> &segmentTreeArr, vector<lli> &original, lli qlow, lli qhigh, lli low, lli high, lli pos)
{
    if(low == high)
    {
        return segmentTreeArr[pos];
    }
    else if(qlow <= low && qhigh >= high)
    {
        return segmentTreeArr[pos];
    }
    else if(qlow > high || qhigh < low)
    {
        return numeric_limits<lli>::min();
    }
    else
    {
        lli mid = (low + high)/2;
        return( max( findMax(segmentTreeArr, original, qlow, qhigh, low, mid, 2*pos+1), findMax(segmentTreeArr, original, qlow, qhigh, mid+1, high, 2*pos+2)));
    }
    return 0;   // need to return because hackerrank's c++ compiler mandates it.
}

int main()
{
    lli n, q;
    cin >> n >> q;
    lli x, y;
    
    vector< pair<lli, lli> > buildingsPosSet;
    vector<lli> xPos;
    for(lli i=0; i<n; i++)
    {
        cin >> x >> y;
        buildingsPosSet.push_back(make_pair(x, y));
        xPos.push_back(x);
    }

    sort(buildingsPosSet.begin(), buildingsPosSet.end());
    sort(xPos.begin(), xPos.end());

    vector<lli> buildingsPos;

    for(lli i=0; i<n; i++)
        buildingsPos.push_back(buildingsPosSet[i].second);

    lli segmentTreeSize = nextPowerOf2(n) * 2 - 1;  // getting smallest power of 2 greater than or equal to n
    lli min = numeric_limits<lli>::min();

    vector<lli> segmentTreeArr(segmentTreeSize, min);

    // creating the segmentTree
    creation(segmentTreeArr, buildingsPos, 0, n-1, 0);

    lli xh, yh, xd, yd; // h->home, d->destination
    lli lb, ub;
    for(lli i=0; i<q; i++)
    {
        lb = -1, ub = -1;
        cin >> xh >> yh >> xd >> yd;
        
        if(xh == xd && yh == yd)
        {
            cout << "0" << endl;
            continue;
        }
        
        // if home is far than the destination itself then swap the two values
        if(xh > xd)
        {
            lli temp = xh;
            xh = xd;
            xd = temp;
            
            temp = yh;
            yh = yd;
            yd = temp;
        }

        lli maxHeight;
        get_bounds(xPos, xh, xd, lb, ub, n);

        if(lb == ub)
            maxHeight = buildingsPos[lb];
        else
            maxHeight =  findMax(segmentTreeArr, buildingsPos, lb, ub, 0, n-1, 0);
    
        lli dis = 0;
        if(maxHeight == yh)
        {
            yh++;
            dis++;
            dis += xd - xh;
            dis += abs(yh - yd);
        }
        else if(maxHeight > yh)
        {
            dis = (maxHeight+1) - yh;
            yh = maxHeight+1;
            dis += xd - xh;
            dis += abs(yh - yd);
        }
        else
        {
            dis = xd - xh;
            dis += abs(yh - yd);
        }
        cout << dis << endl;        
    }
    return 0;
}