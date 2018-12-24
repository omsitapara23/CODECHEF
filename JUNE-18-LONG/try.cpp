#include <bits/stdc++.h>

/*This is copyright of OM SITAPARA IIT HYDERABAD
NO PLAGARISM ALLOWED*/

using namespace std;
typedef long long  ll;

int main()
{
    string s = "om";
    bool ans = lexicographical_compare(s.begin(), s.end(), s.begin(), s.end());
    if(ans == true)
        cout << "1" << "\n";
    else 
        cout << "0" << "\n";

    // ll a = 5, b = 2;
    // cout << (float)a/b << "\n";
    cout << pow(10, -7) << "\n";
    int c= pow(10,9);
    cout << c << "\n";
    cout << double(10)/double(3) << "\n";
    double f = 4;
    double t = f +(pow(0.1, 7)*f);
    cout << setprecision(10) << t << endl;
    double a=pow(10,6);
    cout << a*a*a << endl;

    return 0;
}