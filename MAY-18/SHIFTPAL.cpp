#include <bits/stdc++.h>

/*This is copyright of OM SITAPARA IIT HYDERABAD
NO PLAGARISM ALLOWED*/

using namespace std;


typedef long long ll;

int isPalindrome(string str)
{
    // Start from leftmost and rightmost corners of str
    int l = 0;
    int h = str.length() - 1;
 
    // Keep comparing characters while they are same
    while (h > l)
    {
        if (str[l++] != str[h--])
        {

            return -1;
        }
    }
    return 1;
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
        int len = s.length();
        int gst = 0, count = 0;
        while(true)
        {
            count++;
            if(count > len - 1)
                break;
            
            char f = s[0];
            //cout << f << endl;
            s.erase(0,1);
            //cout << s << endl;
            s = s + f;
            //out << s << endl;
            int pal = isPalindrome(s);
            if(pal == 1)
                gst++;
            
        }

        cout << gst << "\n";
        
    }
    return 0;
}