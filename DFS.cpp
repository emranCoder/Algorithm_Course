#include<bits/stdc++.h>
#define N 10000

using namespace std;

vector<int>graph[N];
bool visit[N];

int DFS(int vertex)
{
    visit[vertex] = true;
     cout << vertex << " ";
    for(auto node:graph[vertex])
    {

        if(!visit[node])
        {
            DFS(node);
        }

    }

}


int main()
{
    int  n,m;
    cin >> n >> m;


    for(int i=0; i<m; i++)
    {
        int v1,v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    cout << "DFS Result: " << endl;
    DFS(1);

    return 0;
}

/*
12 11
1 2
1 3
2 4
2 5
5 6
6 7
3 10
3 8
8 9
10 11
11 12
*/

