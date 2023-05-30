#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<pair<int, int> > adj[], int V, int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    vector<int> dist(V, INT_MAX);
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int weight = adj[u][i].second;
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    cout << "Vertex Distance from Source:" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " " << dist[i] << endl;
}

int main()
{
    int V = 4;
    vector<pair<int, int> > adj[V];
    //0, 1, 4
    //0, 2, 2
    //0, 3, 5
    //2, 3, 1
    adj[0].push_back({1,4});
    adj[1].push_back({0,4});
    adj[0].push_back({2,2});
    adj[2].push_back({0,2});
    adj[0].push_back({3,5});
    adj[3].push_back({0,5});
    adj[2].push_back({3,1});
    adj[3].push_back({2,1});
    dijkstra(adj, V, 0);
    return 0;
}
