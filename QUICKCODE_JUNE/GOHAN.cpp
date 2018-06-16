#include <bits/stdc++.h>

/*This is copyright of OM SITAPARA IIT HYDERABAD
NO PLAGARISM ALLOWED*/

using namespace std;

typedef long long ll;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); 
    int t;
    cin >> t;
    while(t--)
    {
        double r,l,c,v;
        cin >> r >> l >> c >> v;
        double ift = 1 - ((r*r*c)/(4*l));
        printf("%.2f \n", ift);
    }
    return 0;
}