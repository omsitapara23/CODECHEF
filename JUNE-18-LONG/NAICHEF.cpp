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
        int n,a,b;
        cin >> n >> a >> b;
        float p, pa, pb;
        int face;
        int counta = 0;
        int countb  = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> face;
            if(face == a)
                counta++;
            if(face == b)
                countb++;
        }
        pa = (float) counta/ (float) n;
        pb = (float) countb/ (float)n;
        p = pa*pb;
        cout << p << "\n";
    }

    return 0;
}