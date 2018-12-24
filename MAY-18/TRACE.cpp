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
        int n;
        cin >> n;
        int a[n][n];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                cin >> a[i][j];
        }

        int maxtrace = 0;
        int count  = 0;
        int temp = 0;
        for(int i = 1; i < n; i++)
        {
            temp = i;
            for(int j = 0; j < n && temp < n; j++)
            {
                count += a[temp][j];
                temp++;
            }
                
            //cout << "Got count" << count << "\n";
            if(count > maxtrace)
                maxtrace = count;

            count = 0;
        }

         for(int i = 0; i < n; i++)
        {
            temp = i;
            for(int j = 0; j < n && temp < n; j++)
            {
                count += a[j][temp];
                temp++;
            }
                
            //cout << "Got count" << count << "\n";
            
            if(count > maxtrace)
                maxtrace = count;

            count = 0;
        }

        cout << maxtrace << "\n";
        
    }
    return 0;
}