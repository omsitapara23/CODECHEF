// #include <bits/stdc++.h>

// /*This is copyright of OM SITAPARA IIT HYDERABAD
// NO PLAGARISM ALLOWED*/

// using namespace std;

// typedef long long ll;

// int prefix(string s1, string query)
// {
//     int count = 0;
//     int i = 0;
//     while(s1[i] == query[i])
//     {
//         i++;
//         count++;
//     }

//     return count;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); 
  
//     int N;
//     cin >> N;
//     string strings[N];
//     for(int i = 0; i < N; i++)
//         cin >> strings[i];
//     int Q;
//     cin >> Q;
//     while(Q--)
//     {
//         int num;
//         string query;
//         cin >> num >> query;
//         int arrayCount[num];
//         for(int i = 0; i < num; i++)
//         {
//             arrayCount[i] = prefix(strings[i], query);
//         }
//         int max = arrayCount[0];
//         string maxstr = strings[0];
//         for(int i  = 0; i < num; i++)
//         {
//             if(arrayCount[i] > max)
//             {
//                 max = arrayCount[i];
//                 maxstr = strings[i];
//             }
//             else if(arrayCount[i] == max)
//             {
                
//                 if(lexicographical_compare(strings[i].begin(), strings[i].end(), maxstr.begin(), maxstr.end()))
//                     maxstr = strings[i];
//             }
//         } 

//         cout << maxstr << "\n";       
//     } 
//     return 0;
// }



#include <bits/stdc++.h>

/*This is copyright of OM SITAPARA IIT HYDERABAD
NO PLAGARISM ALLOWED*/

using namespace std;

typedef long long ll;

struct stringsSort
{
    string s;
    int position;
};

bool sortStrings(stringsSort a, stringsSort b)
{
    return lexicographical_compare(a.s.begin(), a.s.end(), b.s.begin(), b.s.end());
}

int prefix(string s1, string query)
{
    int count = 0;
    int i = 0;
    while(s1[i] == query[i])
    {
        i++;
        count++;
    }

    return count;
}

string bruteForce(int num, string query, string strings[])
{
    int arrayCount[num + 1];
    for(int i = 1; i <= num; i++)
    {
        arrayCount[i] = prefix(strings[i], query);
    }
    int max = arrayCount[1];
    string maxstr = strings[1];
    for(int i  = 1; i <= num; i++)
    {
        if(arrayCount[i] > max)
        {
            max = arrayCount[i];
            maxstr = strings[i];
        }
        else if(arrayCount[i] == max)
        {
            
            if(lexicographical_compare(strings[i].begin(), strings[i].end(), maxstr.begin(), maxstr.end()))
                maxstr = strings[i];
        }
    }

    return maxstr;
}

// int binaryMax(stringsSort array[], int num, string query, int N, int left)
// {
//     int l = left, r = N;
//     int mid;
//     int max = -1;
//     int index = -1;
//     string maxstr;
//     while(l<=r)
//     {
//         //cout << "inside" << endl;
//         mid = (l + r)/2;
//         if(array[mid].position <= num)
//         {
//             if(prefix(array[mid].s, query) > max)
//             {
//                 max = prefix(array[mid].s, query);
//                 maxstr = array[mid].s;
//                 index = mid;
//             }
//             else if(prefix(array[mid].s, query) == max && mid > index)
//             {
//                 // if(lexicographical_compare(array[mid].s.begin(), array[mid].s.end(), maxstr.begin(), maxstr.end()))
//                 // {
//                 //     index = mid;
//                 //     maxstr = array[mid].s;
//                 // }
//                 index = mid;
//                 maxstr = array[mid].s;
//             }
//         }

//         if(array[mid].s != query)
//         {

//             if(lexicographical_compare(array[mid].s.begin(), array[mid].s.end(), query.begin(), query.end()))
//                 l = mid + 1;
//             else    
//                 r = mid - 1;
//         }
//         else
//             l = mid + 1;
        


//        // cout << "l = " << l << "r = " << r << "index" << index << "\n";


//     }
//     if(index != -1)
//         return index;
//     else
//     {
//         if(r < 1)
//             return 0;
//         else
//             return -1;
//     }

// }

int binaryMax(stringsSort array[], int num, string query, int N, int left)
{
    int l = left, r = N;
    int mid;
    int max = -1;
    int index = -1;
    string maxstr;
    while(l<=r)
    {
        //cout << "inside" << endl;
        mid = (l + r)/2;
        if(array[mid].position <= num)
        {
            if(prefix(array[mid].s, query) > max)
            {
                max = prefix(array[mid].s, query);
                maxstr = array[mid].s;
                index = mid;
                
            }
            else if(prefix(array[mid].s, query) == max && mid > index)
            {
                // if(lexicographical_compare(array[mid].s.begin(), array[mid].s.end(), maxstr.begin(), maxstr.end()))
                // {
                //     index = mid;
                //     maxstr = array[mid].s;
                // }
                index = mid;
                maxstr = array[mid].s;
                
            }

            if(lexicographical_compare(array[mid].s.begin(), array[mid].s.end(), query.begin(), query.end()))
                    l = mid + 1;
                else    
                    r = mid - 1;
        }

        // if(array[mid].s != query)
        // {

        //     if(lexicographical_compare(array[mid].s.begin(), array[mid].s.end(), query.begin(), query.end()))
        //         l = mid + 1;
        //     else    
        //         r = mid - 1;
        // }
        // else
        //     l = mid + 1;

        if(array[mid].position > num)
        {
            if(array[r].position <= num)
            {
                if(prefix(array[r].s, query) >= max)
                {
                    max = prefix(array[r].s, query);
                    maxstr = array[r].s;
                    index = r;
                }
            }

            r--;
        }
        


        //cout << "l = " << l << "r = " << r << "index" << index << "\n";


    }
    if(index != -1)
        return index;
    else
    {
        if(r < 1)
            return 0;
        else
            return -1;
    }

}

int binaryMax2(stringsSort array[], int num, string query, int N)
{
    int l = 1, r = N;
    int mid;
    int max = prefix(array[N].s,query);
    int index = N;
    string maxstr = array[N].s;
    while(l<=r)
    {
        mid = (l + r)/2;
        if(array[mid].position <= num)
        {
            if(prefix(array[mid].s, query) == max && mid <= index)
            {
                max = prefix(array[mid].s, query);
                maxstr = array[mid].s;
                index = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;

        }

        if(array[mid].position > num)
        {
            if(array[l].position <= num)
            {
                if(prefix(array[l].s, query) == max && l <= index)
                {
                    return l;
                }
            }
            
            l++;
        }
    }


    return index;

}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
  
    int N;
    cin >> N;
    stringsSort strings[N + 1];
    string stringsl[N + 1];
    for(int i = 1; i < N + 1; i++)
    {
        cin >> strings[i].s;
        stringsl[i] = strings[i].s;
        strings[i].position = i;
    }

    sort(strings + 1, strings + N + 1, sortStrings);
    // for(int i = 1; i < N + 1; i++)
    // {
    //     cout << strings[i].s << endl;
    //     cout << strings[i].position << endl;
    // }


    int q;
    cin >> q;
    while(q--)
    {
        int num;
        string query;
        cin >> num >> query;
        int answer;
        int left = 1;
        int dN = N;
        do
        {
            answer = binaryMax(strings, num, query, dN, left);
            //cout << "ans" << answer << "\n";
            if(answer == 0)
                left = (left + dN)/2 + 1;
            else if(answer == -1)
                dN = (dN + left)/2  - 1;
        }while(answer < 1 && left <= dN);
        // answer = binaryMax(strings, num, query, dN, left);
        
        //cout << "HGOT ANS :" << answer << endl;
        // cout << strings[answer].s << "\n";
        if(answer > 0)
        {

            int fanswer = binaryMax2(strings, num, query, answer);
            cout << strings[fanswer].s << "\n";
        }
        else
            cout << bruteForce(num, query, stringsl) << "\n";
        // int fanswer = 1;
        // string maxstr = strings[answer].s;
        // int maxer = prefix(strings[answer].s, query);
        // while(fanswer <= answer)
        // {
        //     if(strings[fanswer].position <= num)
        //     {
        //         if(prefix(strings[fanswer].s, query) == maxer)
        //         {
        //             maxstr = strings[fanswer].s;
        //             break;
        //         }
        //         else
        //             fanswer++;
        //     }
        //     else
        //         fanswer++;
        // }
        // cout << maxstr << "\n";
        


    }
    
    
    return 0;
}