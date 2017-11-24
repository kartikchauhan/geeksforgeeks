#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector< vector<char> > num(n, vector<char>(m));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cin >> num[i][j];
    }
    
    int sum = 0;

    vector< vector<bool> > check(n, vector<bool>(m, false));

    for(int i=0; i<n-1; i++)    
    {
        for(int j=0; j<m-1; j++)
        {
            vector<int> count(4, 0);

            bool flag = false;

            if(check[i][j] || check[i][j+1] || check[i+1][j] || check[i+1][j+1])
                flag = true;

            count[num[i][j]-'a']++;
            count[num[i+1][j]-'a']++;
            count[num[i][j+1]-'a']++;
            count[num[i+1][j+1]-'a']++;

            for(int k=0; k<4; k++)
            {
                if(count[k] > 1)
                {
                    flag = true;
                    break;
                }
            }

            if(!flag && num[i][j] == 'a')
            {
                if(num[i+1][j+1] == 'b')
                    flag = true;
            }
            else if(!flag && num[i][j+1] == 'a')
            {
                if(num[i+1][j] == 'b')
                    flag = true;
            }
            else if(!flag && num[i+1][j] == 'a')
            {
                if(num[i][j+1] == 'b')
                    flag = true;
            }
            else if(!flag && num[i+1][j+1] == 'a')
            {
                if(num[i][j] == 'b')
                    flag = true;
            }

            if(!flag && num[i][j] == 'b')
            {
                if(num[i+1][j+1] == 'c')
                    flag = true;
            }
            else if(!flag && num[i][j+1] == 'b')
            {
                if(num[i+1][j] == 'c')
                    flag = true;
            }
            else if(!flag && num[i+1][j] == 'b')
            {
                if(num[i][j+1] == 'c')
                    flag = true;
            }
            else if(!flag && num[i+1][j+1] == 'b')
            {
                if(num[i][j] == 'c')
                    flag = true;
            }

            if(!flag && num[i][j] == 'c')
            {
                if(num[i+1][j+1] == 'd')
                    flag = true;
            }
            else if(!flag && num[i][j+1] == 'c')
            {
                if(num[i+1][j] == 'd')
                    flag = true;
            }
            else if(!flag && num[i+1][j] == 'c')
            {
                if(num[i][j+1] == 'd')
                    flag = true;
            }
            else if(!flag && num[i+1][j+1] == 'c')
            {
                if(num[i][j] == 'd')
                    flag = true;
            }

            if(flag == false)
            {
                sum++;
                check[i][j] = check[i][j+1] = check[i+1][j] = check[i+1][j+1] = true;
            }


        }

    }

    for(int i=0; i<n; i++)    
    {
        for(int j=0; j<m-3; j++)
        {
            vector<int> count(4, 0);

            bool flag = false;

            if(check[i][j] || check[i][j+1] || check[i][j+2] || check[i][j+3])
                flag = true;
            
            count[num[i][j]-'a']++;
            count[num[i][j+1]-'a']++;
            count[num[i][j+2]-'a']++;
            count[num[i][j+3]-'a']++;

            for(int k=0; k<4; k++)
            {
                if(count[k] > 1)
                {
                    flag = true;
                    break;
                }
            }

            if(!flag && num[i][j] == 'a')
            {
                if(num[i][j+1] == 'b')
                    flag = false;
                else
                    flag = true;
            }
            else if(!flag && num[i][j+1] == 'a')
            {
                if(num[i][j] == 'b' || num[i][j+2] == 'b')
                    flag = false;
                else
                    flag = true;
            }
            else if(!flag && num[i][j+2] == 'a')
            {
                if(num[i][j+1] == 'b' || num[i][j+3] == 'b')
                    flag = false;
                else
                    flag = true;
            }
            else if(!flag && num[i][j+3] == 'a')
            {
                if(num[i][j+2] == 'b')
                    flag = false;
                else
                    flag = true;
            }

            if(!flag && num[i][j] == 'b')
            {
                if(num[i][j+1] == 'c')
                    flag = false;
                else
                    flag = true;
            }
            else if(!flag && num[i][j+1] == 'b')
            {
                if(num[i][j] == 'c' || num[i][j+2] == 'c')
                    flag = false;
                else
                    flag = true;
            }
            else if(!flag && num[i][j+2] == 'b')
            {
                if(num[i][j+1] == 'c' || num[i][j+3] == 'c')
                    flag = false;
                else
                    flag = true;
            }
            else if(!flag && num[i][j+3] == 'b')
            {
                if(num[i][j+2] == 'c')
                    flag = false;
                else
                    flag = true;
            }

            if(!flag && num[i][j] == 'c')
            {
                if(num[i][j+1] == 'd')
                    flag = false;
                else
                    flag = true;
            }
            else if(!flag && num[i][j+1] == 'c')
            {
                if(num[i][j] == 'd' || num[i][j+2] == 'd')
                    flag = false;
                else
                    flag = true;
            }
            else if(!flag && num[i][j+2] == 'c')
            {
                if(num[i][j+1] == 'd' || num[i][j+3] == 'd')
                    flag = false;
                else
                    flag = true;
            }
            else if(!flag && num[i][j+3] == 'c')
            {
                if(num[i][j+2] == 'd')
                    flag = false;
                else
                    flag = true;
            }
    
            if(flag == false)
            {
                sum++;
                check[i][j] = check[i][j+1] = check[i][j+2] = check[i][j+3] = true;
            }

        }

    }

    cout << sum;
    return 0;
}