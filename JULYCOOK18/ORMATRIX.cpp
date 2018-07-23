#include <bits/stdc++.h>

/*This is copyright of OM SITAPARA IIT HYDERABAD
NO PLAGARISM ALLOWED*/

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        int a[n][m];
        string s;
        char c;
        for(int i = 0; i < n; i++)
        {
            cin >> s;
            for(int j = 0; j < m; j++)
            {
                c = s[j];
                a[i][j] = c - '0';
            }
        }

        int flag = 0;
        int result[n][m] = {0};

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(a[i][j] == 1)
                {
                    flag = 1;
                    result[i][j] = 0;
                    for(int k = 0; k < m; k++)
                    {
                        if(a[i][k] == 0)
                            result[i][k] = 1;
                    } 

                    for(int k = 0; k < n; k++)
                    {
                        if(a[k][j] == 0)
                            result[k][j] = 1;
                    }
                }
            }
        }

        if(flag == 0)
        {
            // for(int i = 0; i < n; i++)
            // {
            //     for(int j = 0; j < m; j++)
            //         cout << "-1" << " ";
            //     cout << "\n";
            // }

            cout << "-1" << "\n";
        }
        else
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(result[i][j] == 0 && a[i][j] == 0)
                        cout << 2 << " ";
                    else
                        cout << result[i][j] << " ";
                }

                cout << "\n";
            }
        }

    }
    return 0;
}