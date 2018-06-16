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
        ll x1,x2,x3,v1,v2;

        cin >> x1 >> x2 >> x3 >> v1 >> v2;

        ll d1 = x3 - x1, d2 = x2 - x3;

        ll c1 = d1*v2, c2 = d2*v1;
        if(c1 < c2)
            cout << "Chef" << "\n";
        else if (c1 == c2)
            cout << "Draw" << "\n";
        else
            cout << "Kefa" << "\n";
    }

    return 0;
}