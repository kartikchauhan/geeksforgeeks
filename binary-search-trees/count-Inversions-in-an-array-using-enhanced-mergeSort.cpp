// Count Inversions in an array using enhanced mergeSort. Time complexity: O(nLogn)

#include <bits/stdc++.h>

using namespace std;

int merge(vector<int> &num, int p, int q, int r)
{
    int lval = q-p+1;
    vector<int> lv(lval+1);
    
    int rval = r-q;
    vector<int> rv(rval+1);
    
    lv[lval] = numeric_limits<int>::max();
    rv[rval] = numeric_limits<int>::max();
    
    for(int i=0; i<lval; i++)
        lv[i] = num[p+i];

    for(int i=0; i<rval; i++)
        rv[i] = num[q+i+1];
    
    int i = 0, j = 0;
    int inv = 0;    // inversions
    
    for(int k=p; k<=r; k++)
    {
        if(lv[i] <= rv[j])
        {
            num[k] = lv[i];
            i++;
        }
        else if(lv[i] > rv[j])
        {
            if(lv[i] != numeric_limits<int>::max())
                inv += lval-i;
            num[k] = rv[j];
            j++;
        }
    }
    return inv;
}

int mergeSort(vector<int> &num, int p, int r)
{   
    int inv = 0;
    if (p < r)
    {
        int q = (p+r)/2;
        inv = mergeSort(num, p, q);
        inv += mergeSort(num, q+1, r);
        inv += merge(num, p, q, r);     
    }
    return inv;
}

int calcInversions(vector<int> &num)
{
    return mergeSort(num, 0, num.size()-1);
}

int main()
{
    vector<int> num;
    int a;
    
    while(cin >> a)
        num.push_back(a);

    cout << calcInversions(num);
    
    return 0;
}

// Input:
8 1 4 2 9