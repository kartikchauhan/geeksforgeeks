// Triangles everywhere
// https://www.hackerearth.com/challenge/competitive/november-circuits-17/algorithm/triangles-everywhere-86722cb7/

#include <bits/stdc++.h>
#define lli long long int
using namespace std;

lli stringToNumber(string s)
{
    lli length = s.length();
    lli result = 0;
    for(lli i=0; i<length; i++)
        result = result * 10 + (s[i] - '0');

    return result;
}

string multiply(string num1, string num2)
{
    lli n1 = num1.size();
    lli n2 = num2.size();
    if (n1 == 0 || n2 == 0)
       return "0";

    vector<lli> result(n1 + n2, 0);
 
    lli i_n1 = 0; 
    lli i_n2 = 0; 
 
    for (lli i=n1-1; i>=0; i--)
    {
        lli carry = 0;
        lli n1 = num1[i] - '0';
 
        i_n2 = 0; 
         
        for (lli j=n2-1; j>=0; j--)
        {
            lli n2 = num2[j] - '0';
            lli sum = n1*n2 + result[i_n1 + i_n2] + carry;
            carry = sum/10;
            result[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }
 
        if (carry > 0)
            result[i_n1 + i_n2] += carry;
 
        i_n1++;
    }
 
    lli i = result.size() - 1;
    while (i>=0 && result[i] == 0)
       i--;
 
    if (i == -1)
       return "0";
 
    string s = "";
    while (i >= 0)
        s += std::to_string(result[i--]);
 
    return s;
}

string longDivision(string dividend, lli divisor)
{

    lli result = 0;
    lli dividendSize = dividend.length();
    bool flag = true;

    for(lli i=0; i<dividendSize; i++)
    {        
        result = result * 10 + (dividend[i] - '0');
        if(result > divisor)
        {
            flag = false;
            break;
        }
    }

    if(flag == true)
    {
        if(result == divisor)
            return "0";
        else
            return dividend;
    }


    lli index = 0;
    lli temp = dividend[index] - '0';   // get the first number from the dividend and convert it to llieger

    // get the first number from the dividend part which is greater than divisor
    while(temp < divisor)
        temp = temp * 10 + (dividend[++index] - '0');     // getting the next number and appending it to temp

    while(dividendSize > index)
    {
        index++;
        if(dividendSize == index)
            temp = temp % divisor;
        else
            temp = (temp % divisor) * 10 + dividend[index] - '0';
    }

    string finalResult = to_string(temp);

    return finalResult;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    lli q, n;
    cin >> q;

    vector<lli> num;
    num.push_back(1);
    num.push_back(5);
    lli index = 1;

    string power = "1";
    lli mod  = pow(10, 9) + 7;

    while(q--)
    {
        cin >> n;
        if(n <= index)
            cout << num[n] << "\n";
        else
        {
            for(index=index+1; index <=n; index++)
            {
                power = multiply(power, "3");
                power = longDivision(power, mod);
                string result = longDivision(power, mod);
                lli anotherResult = stringToNumber(result);
                anotherResult = ((((anotherResult % mod) * 4) % mod ) + (num[index-1] % mod)) % mod;
                num.push_back(anotherResult);
            }
            index--;
            cout << num[n] << "\n";
        }
    }
    return 0;
}
