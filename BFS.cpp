#include<bits/stdc++.h>
#define N 10000

using namespace std;

vector<int>graph[N];
bool visit[N];
int vertex;


int BFS(int s)
{
    queue<int>q;
    q.push(s);
    visit[s]= true;

    cout << "Started From: " << s << endl;
    cout << "BFS Result: " << s << " ";
    while(!q.empty())
    {
        int head = q.front();
        q.pop();
        for(auto node:graph[head])
        {
            if(!visit[node])
            {
                visit[node] = true;
                q.push(node);
                cout << node << " ";
            }
        }
    }
}


int main()
{
    int  n,m;
    cin >> n >> m;

    vertex = n;

    for(int i=0; i<m; i++)
    {
        int v1,v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    BFS(1);

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
