#include <bits/stdc++.h>

/*This is copyright of OM SITAPARA IIT HYDERABAD
NO PLAGARISM ALLOWED*/

using namespace std;

typedef long long ll;

void decToBinary(ll n, int array[])
{
    // Size of an integer is assumed to be 64 bits
    for (int i = 60; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            array[i] = 1;
        else
            array[i] = 0;
    }
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); 
    int t;
    cin >> t;
    while(t--)
    {
        ll a, b;
        cin >> a >> b;

        if(a == b)
        {
            cout << "0" << "\n";
            continue;
        }

        if((a > 0 && b==1) || b == 0)
        {
            cout << "-1" << "\n";
            continue;
        }
        
        int arraya[61], arrayb[61];
        for(int i = 0; i < 61; i++)
        {
            arraya[i] = 0;
            arrayb[i] = 0;
        }
        decToBinary(a, arraya);
        decToBinary(b, arrayb);
        // for(int i = 0; i < 61; i++)
        //     cout << arraya[i];
        // cout << "\n";
        // for(int i = 0; i < 61; i++)
        //     cout << arrayb[i];
        // cout <<  "\n";
        int counta = 0, countbb = 0;
        int k =0;
        int steps = 0;

        // for(int i = 0; i < 61; i++)
        // {
        //     cout << arrayb[i];

        // }
        // cout << endl;
        while(arrayb[k] != 1)
        {
           // cout << "came in" << endl;
            arrayb[k] = 1;
            k++;
        }
        arrayb[k] =  0;
        // for(int i = 0; i < 61; i++)
        //     cout << arrayb[i];
        // cout << "\n";
        for(int i = 0; i < 61; i++)
        {
            if(arraya[i] == 1)
                counta++;

            if(arrayb[i] == 1)
                countbb++;

        }
        //  for(int i = 0; i < 61; i++)
        // {
        //     cout << arrayb[i];

        // }
        //cout << "count a ===" << counta << "cb ==" << countbb << "\n";

        if(countbb > counta)
        {
            steps = countbb - counta + 1;
        }
        else if (countbb < counta)
            steps = 2;
        else
            steps = 1;

        cout << steps << "\n";
        

    }
    return 0;
}