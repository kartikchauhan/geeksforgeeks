// Divide large number represented as string
// Dividend is a string and divisor is an integer

#include <bits/stdc++.h>
using namespace std;

string longDivision(string dividend, int divisor)
{
	string ans = "";
	int index = 0;
	int temp = dividend[index] - '0';	// get the first number from the dividend and convert it to integer

	// get the first number from the dividend part which is greater than divisor
	while(temp < divisor)
	{
		index++;
		temp = temp * 10 + (dividend[index] - '0');		// getting the next number and appending it to temp
	}

	int dividendSize = dividend.length();

	while(dividendSize > index)
	{
		ans += (temp / divisor) + '0';		// get the result when temp is divided by divisor and convert it to char
		index++;
		temp = (temp % divisor) * 10 + dividend[index] - '0';
	}

	if(ans.length() == 0)
		return "0";
	return ans;
}

int main()
{
	string dividendString;
	cin >> dividendString;
	int divisor;
	cin >> divisor;

	cout << longDivision(dividendString, divisor);

}
// Input:
1248163264128256512
125