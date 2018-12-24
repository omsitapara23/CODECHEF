#include <bits/stdc++.h>

/*This is copyright of OM SITAPARA IIT HYDERABAD
NO PLAGARISM ALLOWED*/

using namespace std;

typedef long long ll ;

long double distance(long double qx, long double qy, long double qz, long double px, long double py, long double pz)
{
    long double square = ((qx - px)*(qx - px) + (qy - py)*(qy - py) + (qz - pz)*(qz - pz));
    return sqrt(square);
}

long double radiusC(long double qx, long double qy, long double qz, long double px, long double py, long double pz, long double cx, long double cy, long double cz)
{
    long double vecP = (qx - px)*(cx - px) + (qy - py)*(cy - py) + (qz - pz)*(cz - pz);
    long double cosA = vecP/(distance(qx,qy,qz,px,py,pz)*distance(cx,cy,cz,px,py,pz));
    long double sinA = sqrt(1 - cosA*cosA);
    long double radius = distance(cx,cy,cz,px,py,pz)*sinA;
    return radius;
}

int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int ts;
    cin >> ts;
    while(ts--)
    {
        long double px,py,pz;
        long double qx,qy,qz;
        long double dx,dy,dz;
        long double cx,cy,cz;
        long double rd;
        cin >> px >> py >> pz;
        cin >> qx >> qy >> qz;
        cin >> dx >> dy >> dz;
        cin >> cx >> cy >> cz;
        cin >> rd;
        int t;
        long double error = pow(10, -8);
        int l = 0, r = pow(10,9);
        int mid;
        long double radius;
        long double err;
            //     break;
        int breaker = 0;
        //while(l<=r)
        // {
        //     mid = (l + r)/2;
        //     t = mid;
        //     radius = radiusC(qx + dx*t, qy + dy*t, qz + dz*t, px, py, pz, cx, cy, cz);
        //     cout << "FOr time t" << t << " radius is  " << radius << "\n";
        //     err = abs(radius - rd);
        //     cout << err << "\n";
        //     if(err < error)
        //         break;
        //     if(radius - rd > 0)
        //         r = mid - 1;
        //     else 
        //         l = mid + 1;

            
        // }

        for(int i = 0; i <= r; i++)
        {
            t = i;
            radius = radiusC(qx + dx*t, qy + dy*t, qz + dz*t, px, py, pz, cx, cy, cz);
            //cout << "FOr time t" << t << " radius is  " << radius << "\n";
            err = abs(radius - rd);
            if(err < error)
            {
                breaker = 1;
                break;
            }
            if(radius - rd > 0)
                break;

        }

        if(breaker != 1)
            t = t - 1;
        else
        {
            cout << t << "\n";
            continue;
        }
        breaker = 0;
        long double times = (long double)t;
        int decimal = 1;
        long double timesc;
        long double lastr;
        while(decimal <= 10)
        {
            for(int i = 0; i <= 9; i++)
            {
                timesc = times + pow(0.1,decimal)*i;
                radius = radiusC(qx + dx*timesc, qy + dy*timesc, qz + dz*timesc, px, py, pz, cx, cy, cz);
                //cout << setprecision(10) << "FOr time timsec" << timesc << " radius is  " << radius << "\n";
                err = abs(radius - rd);
                // if(err < error)
                // {
                //     breaker = 1;
                //     break;
                // }
                if(radius - rd > 0)
                {
                    breaker = 2;
                    break;
                }

            }

            if(breaker == 2)
            {
                times = timesc - pow(0.1, decimal);
            }
            else if(breaker == 1)
            {
                times = timesc;
                break;
            }
            else
                times = timesc;
            
            breaker = 0;
            decimal++;
        }
        

        

        cout <<setprecision(11) << times << "\n";

        
    }
    return 0;
}
    