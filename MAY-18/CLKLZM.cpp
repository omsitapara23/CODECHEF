#include <bits/stdc++.h>

/*This is copyright of OM SITAPARA IIT HYDERABAD
NO PLAGARISM ALLOWED*/

using namespace std;

struct beam 
{
    int l;
    int r;
    int h;
    int rg;
    int u;
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        int zombie[n + 1];
        
        for(int i = 1; i <= n; i++)
        {
            cin >> zombie[i];
        }

        struct beam beams[m + 1];

        // cout << "before" << endl;
        
        
        for(int i = 1; i <= m; i++)
        {
            cin >> beams[i].l >> beams[i].r >> beams[i].h;
        }

        for(int i = 1; i <= m; i++)
        {
            beams[i].rg = beams[i].r - beams[i].l;
            beams[i].u = 1;
        }

        int ml,mr,mh,mrg = 0;
        int cbeam = 0;
        int zh = 0;
        int counter = 0;
        int cont = 1;
        int tr = 1;
        int des = 0;
        int mindes = 0;
        int mc = m;
        int no = 0;
        // cout << "before" << endl;
        while(cont == 1 && tr == 1)
        // while(mc--)
        {
            ml = 0;
            mr = 0;
            mh = 0;
            mrg = 0;
            cbeam = 0;
            des = 0;
            mindes = 0;
            // cout << "coming " << endl;

            for(int i = 1; i <= m; i++)
            {
                if(beams[i].h != 0 && beams[i].u == 1)
                {
                    for(int j = beams[i].l; j  <= beams[i].r; j++)
                    {
                        if(zombie[j] > 0)
                            des += zombie[j];
                    }
                    // if(beams[i].rg > mrg)
                    // {
                    //     ml = beams[i].l;
                    //     mr = beams[i].r;
                    //     mh = beams[i].h;
                    //     mrg = beams[i].rg;
                    //     cbeam = i;
                    // }
                    if(des > mindes)
                    {
                        ml = beams[i].l;
                        mr = beams[i].r;
                        mh = beams[i].h;
                        mrg = beams[i].rg;
                        cbeam = i;
                        mindes = des;
                    }

                    des = 0;
                }
            }

            // cout << "SELECTING " << cbeam << endl;
            // cout << "THE SELECTION" << ml << "  " << mr << "  " << mh << endl; 

            zh = 0;
            
            for(int i = ml; i <= mr; i++)
            {
                if(zombie[i] > zh)
                    zh = zombie[i];
            }

            if(zh == 0)
                beams[cbeam].u = 0;
            else
            {
                if(zh <= mh)
                {
                    for(int i = ml; i <= mr; i++)
                    {
                        zombie[i] -= zh;
                        
                    }
                    counter += zh;
                    beams[cbeam].h -= zh;
                    beams[cbeam].u = 0;
                }
                else
                {
                    for(int i = ml; i <= mr; i++)
                    {
                        zombie[i] -= mh;
                        
                    }
                    beams[cbeam].h = 0;
                    beams[cbeam].u = 0;
                    counter += mh;
                }
            }
            cont = 0;
            for(int i = 1; i <= n; i++)
            {
                if(zombie[i] > 0)
                    cont = 1;
            }
            tr = 0;
            if(cont == 1)
            {
                for(int i = 1; i <= m; i++)
                {
                    if(beams[i].u != 0)
                    {
                         tr = 1;
                        //  cout << "beam " << i << "is active" << endl;
                    }
                       
                }
            }

            // // cout << "PRINTING ZOMMM" << endl;
            // for(int i  = 1; i <= n; i++)
            //     cout << "  " << zombie[i] << endl;

            if(cont == 1 && tr == 0)
            {
                cout << "NO" << "\n";
                no = 1;
            }



        }

        if (no == 0)
            cout << "YES " << counter << "\n";

     
        
    }

    return 0;
}