#include <bits/stdc++.h>

/*This is copyright of OM SITAPARA IIT HYDERABAD
NO PLAGARISM ALLOWED*/

using namespace std;

typedef long long ll;

int primeFactors(int n)
{
    int count = 0;
    int once = 0;
    while (n%2 == 0)
    {
        if(once == 0)
        {
            once = 1;
            count+=1;
        }
        n = n/2;
    }
    once = 0;
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            if(once == 0)
            {
                once = 1;
                count+=1;
            }
           
            n = n/i;
        }

        once = 0;
    }
    if (n > 2)
        count++;

    return count;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin>> n >> m;
        int fenergy = 0;
        for(int i = n; i< m; i++)
        {
            //cout << "Adding " << primeFactors(i) << "\n";
            fenergy += primeFactors(i);
        }
        cout << fenergy << "\n";
    }
    return 0;
}