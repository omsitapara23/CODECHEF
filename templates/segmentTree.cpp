#include <bits/stdc++.h>

using namespace std;

/*This is a copyright of OM SITAPARA IIT HYDERABAD
No plagarism is allowed*/

/*THIS CODE HAS ONE BASED INDEXING FOR THE ARRAYS OF INPUT
AND THE SEGEMENT TREE ARRAY SO BE CAREFUL WHILE MAKEING ANY 
CHANGE OR UPDATING ANY KIND FUNCTION AND PASSING PARAMETERS IN 
THE FUNCTIONS*/
int* tree;
int* A;
void build(int node, int start, int end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        tree[node] = A[start];
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        // Leaf node
        A[idx] += val;
        tree[node] += val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2*node, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

int query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
}

int main()
{
    int n;
    cout << "Enter the size of array" << endl;
    cin >> n;
    A = new int[n + 1];
    tree = new int[2*n + 1];
    cout << "Enter the array" << endl;
    for(int i = 1; i<=n; i++)
    {
        cin>> A[i];
    }
    build(1, 1, n);
    int z, l ,r;

    do
    {
        cin >> z;
        cin >> l >> r;
        cout << query(1, 1, n, l, r) << endl;

    }while(z==1);

    return 0;
}