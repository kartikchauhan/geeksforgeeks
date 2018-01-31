// array right rotation by d elements
// make suitable modifications in rotateArrayRight function to make the program work for left rotation

#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b)
{
    if(b == 0)
        return a;
    else 
        return GCD(b, a%b);
}

void rotateArrayRight(vector<int> &num, int d, int n)
{    
    int gcd;

    if(n > d)
        gcd = GCD(n, d);
    else
        gcd = GCD(d, n);

    for(int i=1; i<=gcd; i++)
    {
        int temp = num[n-i];

        int j = n-i;

        while(1)
        {
            int k = j - (d % n);

            if(k < 0)
                k = k + n;

            if(k == n-i)
                break;

            num[j] = num[k];

            j = k;
        }

        num[j] = temp;
    }
}

int main()
{
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> num(n);

    for(int i=0; i<n; i++)
        cin >> num[i];

    rotateArrayRight(num, k, n);

    for(int i=0; i<n; i++)
        cout << num[i] << " ";

    return 0;
}