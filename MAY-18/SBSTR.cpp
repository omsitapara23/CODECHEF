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
        string s;
        cin >> s;
        int k;
        cin >> k;

        int dist[26];
        for(int i = 0; i < 26; i++)
            dist[i] = 0;
        int len = k;
        int count = 0;
        char temp;
        int gst = 0;
        int freq = 0;
        int breaker = 0;
        while(len <= s.length())
        {
            for(int i = 0; i < s.length() - len + 1; i++)
            {
                for(int j = i; j < i + len; j++)
                {
                    temp = s[j];
                    dist[(int)temp - 97]++;
                }

                for(int i = 0; i < 26; i++)
                {
                    if(dist[i] != 0)
                    {
                        count++;
                        if(count == 1)
                        {
                            freq = dist[i];
                        }
                        else if(dist[i] != freq)
                        {
                            breaker = 1;
                            break;
                        }
                    }
                }

                if(breaker != 1 && count >= k)
                {
                    gst++;
                   // cout << "GST increased for lenght" << len << endl;
                }
                
                for(int i = 0 ; i < 26; i++)
                {
                    dist[i] = 0;
                }

                count = 0;
                freq = 0;
                breaker = 0;

            }

            len = len + 1;
        }

        cout << gst << "\n";

    }

    return 0;
}