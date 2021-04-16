#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
 
 #define vi vector<int>





vi bfs(int node, vi visited, vi dist, vi adj[]){
    visited[node] =1;
    dist[node]=0;

    queue<int>q ;
    q.push(node);
    while(!q.empty()){
        int current = q.front();
        q.pop();

        for(auto child :adj[current]){
            if(!visited[child]){
                visited[child]=1;
                q.push(child);
                dist[child] = dist[current]+1;
            }
        }
    }
  return dist;
}
int main(){
    int n;
    cin>>n;
    int a, b;
    vi visited(n+1 , 0);
   
    vi dist(n+1, 0);
    vi adj[1000];
    for(int i=1;i<n;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dist = bfs(1 , visited , dist, adj);

    cout<<dist[n];
     
}