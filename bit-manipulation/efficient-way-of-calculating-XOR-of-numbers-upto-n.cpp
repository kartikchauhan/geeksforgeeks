// efficient way of calculating XOR of numbers upto n


/* This is how it works

Number Binary-Repr  XOR-from-1-to-n
1         1           [0001]
2        10           [0011]
3        11           [0000]  <----- We get a 0
4       100           [0100]  <----- Equals to n
5       101           [0001]
6       110           [0111]
7       111           [0000]  <----- We get 0
8      1000           [1000]  <----- Equals to n
9      1001           [0001]
10     1010           [1011]
11     1011           [0000] <------ We get 0
12     1100           [1100] <------ Equals to n
*/

#include <bits/stdc++.h>
using namespace std;
 
long computeXOR(const int n)
{
 
    switch(n % 4) // n % 4 
    {
    	case 0: return n;     // if n is multiple of 4
    	case 1: return 1;     // If n % 4 gives remainder 1  
    	case 2: return n + 1; // If n % 4 gives remainder 2    
    	case 3: return 0;     // If n % 4 gives remainder 3  
    }
    return 0;
}
 
int main()
{
	int n;
	cin >> n;

    cout << computeXOR(n);
    return 0;
}

// Input:
5