// cycle detection of UNDirected  using bfs

#include <bits/stdc++.h>
#include <vector>
#include <queue>

using namespace std;

bool bfs(int node, vector<int> adj[], vector<int> &flag)
{

    queue<int> q;
    q.push(node);
    flag[node] = 0;
    bool result = false;
    while(!q.empty()){
        int current = q.front();
        q.pop();
        
        for(auto child:adj[current]){
            if(flag[child]==0)
              return true;
            else if(flag[child]==-1){
                q.push(child);
                flag[child]=0;
            }
             
              
        }
        flag[current] = 1;
    }
    return result;
    
}

int main()
{

    int v, e;
    cin >> v >> e;
    vector<int> adj[v+1];
    vector<int> flag(v + 1, -1);

    int a, b;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b;
        adj[b].push_back(a);
        adj[a].push_back(b);
    }

    cout << ((bfs(1, adj, flag)==true) ? "true" : "false");

    return 0;
}