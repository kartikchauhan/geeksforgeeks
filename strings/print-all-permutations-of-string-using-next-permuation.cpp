// print all permutations of string using next_permutation(permutations.h)

#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;

	sort(s.begin(), s.end());

	do
	{
		cout << s << endl;
	}
	while(next_combination(s.begin(), s.end()));

	return 0;
}

// Note : this program ignores duplicate entries and performs permutations for unique values only.