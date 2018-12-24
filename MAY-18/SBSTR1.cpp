#include <bits/stdc++.h>

/*This is copyright of OM SITAPARA IIT HYDERABAD
NO PLAGARISM ALLOWED*/

using namespace std;

int gst = 0;
 int mk;

struct node {
    string s;
    int dist[26];
    struct node* left = NULL;
    struct node* right = NULL;
};

struct node* createNodel (string s, int dist[])
{
    struct node* new_node = new struct node;
    char temp = s[0];
    new_node -> s = s.erase(0,1);
    dist[(int) temp - 97] -= 1;
    int count = 0;
    int freq = 0;
    int breaker = 0;
    for(int i = 0; i < 26; i++)
                {
                    if(dist[i] != 0)
                    {
                        count++;
                        if(count == 1)
                        {
                            freq = dist[i];
                        }
                        else if(dist[i] != freq)
                        {
                            breaker = 1;
                            break;
                        }
                    }
                }
    if(breaker != 1 && count >= mk)
        gst++;

    for(int i = 0; i < 26; i++)
       new_node -> dist[i] = dist[i];

    return new_node;
    
}

struct node* createNoder (string s, int dist[])
{
    struct node* new_node = new struct node;
    char temp = s[s.length() - 1];
    new_node -> s = s.erase(s.length() - 1,1);
    dist[(int) temp - 97] -= 1;
    int count = 0;
    int freq = 0;
    int breaker = 0;
    for(int i = 0; i < 26; i++)
                {
                    if(dist[i] != 0)
                    {
                        count++;
                        if(count == 1)
                        {
                            freq = dist[i];
                        }
                        else if(dist[i] != freq)
                        {
                            breaker = 1;
                            break;
                        }
                    }
                }
    if(breaker != 1 && count >= mk)
        gst++;

    for(int i = 0; i < 26; i++)
       new_node -> dist[i] = dist[i];



    return new_node;
    
}


typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
       
        cin >> mk;
        int len = s.length();
        int dist[26];
        for(int i = 0; i < 26; i++)
            dist[i] = 0;
        for(int i = 0; i < s.length(); i++)
            dist[(int)s[i] - 97]++;
        struct node* head =(struct node*) malloc(sizeof(struct node));
        head -> left = NULL;
        head ->  right = NULL;
        for(int i = 0; i < 26; i++)
            head-> dist[i] = dist[i];
        head -> s = s;
        while(len--)
        {
            
        }

        

        

    return 0;
}