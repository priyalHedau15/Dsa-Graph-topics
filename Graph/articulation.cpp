#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<set>
using namespace std;


#define  vi vector<int>
#define pb push_back   
int timer  ;
set<int> artiPoints;

void dfs_artiPoints(int node , int par, vi adj[], vector<int>&visited, vector<int>&in , vector<int>&low){
  visited[node] =1;
  in[node] = low[node] = timer++;
  int children=0;
  for(auto child:adj[node]){
      if(child==par) continue;
      else if(visited[child]) // back edge
          low[node] = min(low[node], in[child]);

     else{ // forward edge or child isn't visited
          dfs_artiPoints(child , node , adj, visited, in , low );
          low[node] = min(low[node] , low[child]);

          if(low[child] >=in[node] &&par!=-1)
             artiPoints.insert(node);
            
          children++;

     }
  }
  if(par==-1 && children>1)
     artiPoints.insert(node);
}

int main(){

    int n ,e;
    cin>>n>>e;

    vi adj[n+1];
    vi visited;
    visited.assign(n+1,0);
    vi in , low;
    in.assign(n+1 , 0);
    low.assign(n+1 , 0);
    int a, b;
    for(int i=0;i<e;i++){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
   
   dfs_artiPoints( 1, -1, adj, visited, in , low);
   
   for(auto child:artiPoints)
      cout<<child<<" ";

}