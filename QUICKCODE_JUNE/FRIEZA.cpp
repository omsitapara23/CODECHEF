#include <bits/stdc++.h>

/*This is copyright of OM SITAPARA IIT HYDERABAD
NO PLAGARISM ALLOWED*/

using namespace std;

typedef long long ll;

char good[6] = {'f','r','i','e','z','a'}; 

bool checkers(char c)
{
    bool result = false;
    for(int i = 0; i < 6; i++)
    {
        if(good[i] == c)
            result = true;
    }

    return result;
}



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
        vector<int> out;
        int count = 0;
        bool goodc =  checkers(s[0]);
        bool checker = checkers(s[0]);
        for(int i = 0; i < s.length(); i++)
        {
            checker = checkers(s[i]);
            if(checker == goodc)
                count++;
            else
            {
                out.push_back(count);
                count = 1;
                goodc = checker;
            }
        }

        out.push_back(count);

        for(int i = 0; i < out.size(); i++)
            cout << out[i];
        cout << "\n";
    }
    return 0;
}