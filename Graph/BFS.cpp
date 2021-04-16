#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

void addEdge(vector<int>adj[] , int v , int w){
    adj[v].push_back(w);
  
}

void BFS_traversal(int s, bool visited[] , vector<int>adj[]){
   visited[s] = true;
   queue<int> qu ;
    qu.push(s);

    while(!qu.empty()){
        int current = qu.front();
        cout<<current<<" ";
        qu.pop();

        // for(int i =adj[s].begin();i<adj[s].end();i++){
        //     if(visited[i] == false){
        //         qu.push(i);
        //         visited[i]  = true;
        //     }
        // }
        for (auto it: adj[current]) {
            if (!visited[it]) {
                visited[it] = true;
                qu.push(it);
            }

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
  BFS_traversal(0 , vis, adj);
 return 0;
 }