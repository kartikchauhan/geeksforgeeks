#include <bits/stdc++.h>
#define lli long long int
using namespace std;
 
int main()
{
    int t;
    cin >> t;
 
    lli upperRange = pow(10, 9);
    while(t--)
    {
        int n, q;
        cin >> n >> q;
 
        lli product = 1;
        bool flag = false;

        vector<lli> num(n);
        
        for(int i=0; i<n; i++)
        {            
            if(flag == true)
                continue;

            cin >> num[i];

            product *= num[i];

            if(product > pow(10, 9))
                flag = true;
        }
 
        lli x;
        while(q--)
        {
            cin >> x;
            
            if(flag == true)
                cout << 0 << " ";
            else
            {
                x = floor(x/product);
                cout << x << " ";
            }

        }
        cout << endl;
    }
    
    return 0;
}