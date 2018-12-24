#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int d;
        cin >> d;
        int currd, currp;
        int arr[32];
        for(int i = 1; i <= 31; i++)
            arr[i] = 0;
        for(int i = 0; i < d; i++)
        {
            cin >> currd >> currp;
            arr[currd] = currp;
        }

        for(int i = 2; i <= 31; i++)
        {
            arr[i] = arr[i] + arr[i - 1];
        }

        int q;
        cin >> q;
        for(int i = 0; i < q; i++)
        {
            cin >> currd >> currp;
            if(arr[currd] >= currp)
                cout << "Go Camp" << endl;
            else
                cout << "Go Sleep" << endl;
        }
    }

    return 0;
}
