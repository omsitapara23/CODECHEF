
#include<stdio.h>
#include <bits/stdc++.h>

using namespace std;
 
/*This is a copyright of OM SITAPARA IIT HYDERABAD
plagarism of this code will lead to serious penalty*/

typedef long long ll;

 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int n;
    cin >> n;
    int nc = n;
    vector<ll> wt1;
    vector<ll> wt2;
    ll res[200002]={0};
    int w;
    ll c;
    while(nc--)
    {
        cin >> w >> c;
        if(w == 1)
            wt1.push_back(c);
        else
            wt2.push_back(c);

    }

    sort(wt1.begin(), wt1.end());
    sort(wt2.begin(), wt2.end());

    ll W = wt1.size() + wt2.size()*2;

   ll cost = 0;
   ll i1 = wt1.size(), i2 = wt2.size();
    
    for(int i = 2; i <= W; i+=2)
    {
       ll w1 = 0, w2 = 0;
       if(i1 >= 2)
            w1 = wt1[i1 - 1] + wt1[i1 - 2];
       else if (i1 == 1)
            w1 = wt1[i1 - 1];
        if(i2 >= 1)
            w2 = wt2[i2 - 1];
        if(w1 >= w2)
        {
            if(i1 >= 2)
                i1 -= 2;
            else
                i1 -= 1;
            
            cost += w1;
        }
        else
        {
            i2 -= 1;
            cost += w2;
        }
        res[i] = cost;

    }

    cost = 0;
    i1 = wt1.size(), i2 = wt2.size();
    if(wt1.size()>=1){
        cost = wt1[wt1.size()-1];
        i1-=1;
        res[1]=cost;
    }

    for(int i = 3; i <= W; i+=2)
    {
       ll w1 = 0, w2 = 0;
       if(i1 >= 2)
            w1 = wt1[i1 - 1] + wt1[i1 - 2];
       else if (i1 == 1)
            w1 = wt1[i1 - 1];
        if(i2 >= 1)
            w2 = wt2[i2 - 1];
        if(w1 >= w2)
        {
            if(i1 >= 2)
                i1 -= 2;
            else
                i1 -= 1;
            
            cost += w1;
        }
        else
        {
            i2 -= 1;
            cost += w2;
        }
        res[i] = cost;

    }

    for(int i=1;i<=W;i++){
        cout<<res[i]<<" ";
      }
      cout<<endl;
    
    return 0;
}