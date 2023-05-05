#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cout << "Enter The Number of vertex: ";
    cin >> n;
    int edge;
    cout << "Enter The number of Connected Node: ";
    cin>> edge;
    vector<pair<int, int > > adj[n];

    /*Take Input for Graph */
    for(int i =0; i<edge; i++)
    {
        int u,v,wt;
        cin >> u  >> v >> wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    priority_queue< pair<int, int>, vector<pair<int, int> > , greater<pair<int, int> >  > pq;

    int key[n]; // weight stored for the visited node
    int parent[n]; // when the weight changed then the parent will be added there
    bool inMST[n]; // node visited or not

    for(int i=0; i<n; i++)
    {
        key[i]=INT_MAX; // Every key value made infinity.
        inMST[i]= false;// Visiting node all false.
    }
    key[0] = 0;
    parent[0]=-1;
    pq.push({0,0}); // this pair:  first value weight for this node, second value node

    while(!pq.empty())
    {
        int p_node = pq.top().second;//staring node
        pq.pop();
        inMST[p_node] = true;

        for(auto it:adj[p_node])
        {
            int v = it.first; // under staring node all nodes
            int weight = it.second; // current node weight
            if(inMST[v]==false && weight<key[v])
            {
                key[v] = weight; // under staring node all node
                parent[v] = p_node; // changed weight parent valuse added.
                pq.push({key[v], v});
            }
        }
    }

    cout << "Primes MST: " << endl;
    for(int i =1; i<n; i++)
    {
        cout << parent[i] << " - " << i << endl;
    }

    return 0;
}


/*
Input Value:
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
*/
