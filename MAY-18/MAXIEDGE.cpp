#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int N;
        cin >> N;
        int a[26], b[26];
        string s1, s2;
        cin >> s1;
        cin >> s2;
        int pairs = 0;

        for(int i = 0; i < 26; i++)
        {
            a[i] = 0;
            b[i] = 0;
        }

        for(int i = 0; i < N; i++)
        {
            a[(int)s1[i] - 97]++;
            b[(int)s2[i] - 97]++;
        }

        int selected = 1;
        string newS1, newS2;
        int number = 0;
        char add;

        vector<int> even, odd;

        for(int i = 0; i < 26; i++)
        {
            if((a[i] + b[i])%2 == 0)
                even.push_back(i);
            else
                odd.push_back(i);
        }


        for(int i = 0; i < even.size(); i++)
        {
            number = even[i];
            add = (char) (number + 97);
            number = a[even[i]] + b[even[i]];
            for(int j = 0; j < number/2; j++)
            {
                newS1 += add;
                newS2 += add;
            }
        }

        for(int i = 0; i < odd.size(); i++)
        {
            number = odd[i];
            add = (char) (number + 97);
            number = a[odd[i]] + b[odd[i]];
            if(selected == 1)
            {
                for(int j = 0; j < number/2; j++)
                {
                    newS1 += add;
                    newS2 += add;
                }
                newS1 += add;
                selected = 2;
            }
            else
            {
                for(int j = 0; j < number/2; j++)
                {
                    newS1 += add;
                    newS2 += add;
                }
                newS2 += add;
                selected = 1;
            }

        }

        cout << newS1 << endl;
        cout << newS2 << endl;

    }

    return 0;
}







