#include <bits/stdc++.h>

/*This is copyright of OM SITAPARA IIT HYDERABAD
NO PLAGARISM ALLOWED*/

using namespace std;

typedef long long ll;


int main()
{
    int n, q, k;
    cin >> n >> q >> k;
    int in[n];
    for(int i = 0; i < n; i++ )
        cin >> in[i];
    string query;
    cin >> query;
    vector<int> currvec;
    int count = 0;
    int curr_index = 0;
    int curr_max = 0;
    for(int i = 0; i < n; i++)
    {
        if(in[i] == 1)
            count++;
        else
        {

            currvec.push_back(count);
            if(count > curr_max)
            {
                curr_max = count;
                curr_index = 2 - 1;
            }
            count = 0;
        }
    }

    currvec.push_back(count);
    if(count > curr_max)
        curr_index = currvec.size() - 1;

    
    int tot = currvec.size();
    for(int i = 0; i < query.length(); i++)
    {
        if(query[i] == '!')
        {
            if(currvec[tot - 1] == 0)
            {
                curr_index = (curr_index + 1)%tot;
                currvec.insert(currvec.begin(), 0);

            }
                    WQ
            else
            {
                assert(currvec[tot - 1] >= 0);
                currvec[tot - 1]--;
                currvec[0]++;
                if(curr_index == tot - 1)
                {
                    for(int j = 0; j < tot; j++)
                    {
                        if(currvec[j] > currvec[curr_index])
                        {
                            curr_index = j;
                        }

                    }
                }
                else if (currvec[0] >= currvec[curr_index])
                        curr_index = 0;

            }
        }
        else
        {
            if(currvec[curr_index] <= k)
                cout << currvec[curr_index] << endl;
            else
                cout << k << endl;
        }
    }

    return 0;
}