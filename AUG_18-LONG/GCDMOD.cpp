#include <bits/stdc++.h>

/*This is copyright of OM SITAPARA IIT HYDERABAD
NO PLAGARISM ALLOWED*/

using namespace std;

typedef long long ll;

ll moduloMultiplication(ll a,ll b, ll mod)
{
    ll res = 0;  // Initialize result
 
    // Update a if it is more than
    // or equal to mod
    a %= mod;
 
    while (b)
    {
        // If b is odd, add a with result
        if (b & 1)
            res = (res + a) % mod;
 
        // Here we assume that doing 2*a
        // doesn't cause overflow
        a = (2 * a) % mod;
 
        b >>= 1;  // b = b / 2
    }
 
    return res;
}

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = moduloMultiplication(res, x, p);
 
        // y must be even now
        y = y>>1; // y = y/2
        x =moduloMultiplication(x,x, p);  
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t;
    cin >> t;
    while(t--)
    {
        ll a,b,n;
        cin >> a >> b >> n;
        ll diff = a - b;
        if(diff != 0)
        {
            ll numa = power(a,n,diff);
            ll numb = power(b,n,diff);
            ll num = (numa + numb)%diff;
            ll final_gcd = __gcd(diff , num);
            cout << final_gcd%(1000000007) << "\n";
        }
        else
        {
            ll numa = power(a,n,1000000007);
            ll numb = power(b,n,1000000007);
            ll num = (numa + numb)%1000000007;
            cout << num << "\n";
        }
        

    }

    return 0;
}