#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

void addEdge(vector<int>adj[] , int v , int w){
    adj[v].push_back(w);
  
}

void DFS_traversal(int s, bool visited[] , vector<int>adj[] ){
   visited[s] = true;
  
      cout<<s<<" ";
       int c =0;
        for (auto it: adj[s]) {
             
            if (!visited[it]) {
               DFS_traversal(it , visited, adj );
              
            }

    


}
}
int main() {
    int n = 5;
 vector<int>adj[n];
 bool vis[n] = {false};

  
  addEdge(adj , 0, 1);
  addEdge(adj , 1,3);
  addEdge(adj , 1,2);
  addEdge(adj , 2,1);
  addEdge(adj , 2,4);
  addEdge(adj , 3,1);
  addEdge(adj , 3,4);
  addEdge(adj , 4,2);
  addEdge(adj , 4,3);
  DFS_traversal(0 , vis, adj );
 return 0;
 }