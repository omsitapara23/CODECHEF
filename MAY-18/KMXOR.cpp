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
        int n;
        ll k;

        cin >> n >> k;

        if(n == 1)
            cout << k << endl;
        else
        {
             if(k == 1)
        {
            for(int i = 0; i < n - 1; i++)
                cout << "1 "; 
            cout << "1"  << endl;
        }
        else if (k == 2)
        {
           
            int q = n/2;
            for(int i = 0; i < q - 1; i++)
                cout << "1 1 ";
            if(n%2 ==0)
                cout << "1 2" << endl;
            else
                cout << "1 1 2" << endl;
        }
        else
        {
            ll nK = 0;
            ll ck = k;
            for(int i = 0; ;i++)
            {
                //cout << "coming" << endl;
                if(ck == 0)
                    break;
                if(!(ck & 1))
                {
                    //cout << "Adding " << endl;
                    nK += pow(2, i);
                }
                    
                ck = ck >> 1;
            }
            if(nK != 0)
            {
                //cout <<"easy" << endl;
                if(n%2 ==0)
                {
                    int q = n/2;
                    for(int i = 0; i < q - 1; i++ )
                        cout << "1 1 ";
                    cout << nK << " " << k << endl;
                }

                else
                {
                    int q = n/2;
                    for(int i = 0; i < q - 1; i++ )
                        cout << "1 1 ";
                    if(nK & 1)
                        nK = nK - 1;
                    else
                        nK = nK + 1;
                    cout << "1 " << nK << " " << k << endl;
                }
            }
            else
            {
                if(n%2 == 0)
                {
                    int q = n/2;
                    for(int i = 0; i < q - 1; i++ )
                        cout << "1 1 ";
                    cout << "1 " << k - 1 << endl;
                }
                else
                {
                    int q = n/2;
                    for(int i = 0; i < q; i++ )
                        cout << "1 1 ";
                    cout << k << endl;
                }
                
                

            }

            
        }
        }

       
    }
    return 0;
}