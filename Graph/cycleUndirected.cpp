 // cycle detection of Directed and und. using dfs
 
 #include<bits/stdc++.h>
 #include<vector>

 using namespace std;


//  // } Driver Code Ends
// /* This function is used to detect a cycle in undirected graph
// *  adj[]: array of vectors to represent graph
// *  V: number of vertices
// */
// 
// { Driver Code Starts.
bool dfs(int node, vector<vector<int>>arr, int *visited)
{
   visited[node] = 1; 
   for (auto child :arr[node])
   {
       if(!visited[child])
       {
           bool cycleExist =  dfs(child, arr, visited);
           if(cycleExist)
           {
               return true;
           }
       }
       else if(visited[child] == 2)
       {
           return true;
       }
   }
   visited[node] = 2;
   return false;
}

int main()
{
//     freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout) ;
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
      vector<vector<int>>adj(V);
        int visited[V]  ={0};
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            u--, v--;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << (dfs( 0 ,adj, visited)?"true":"false")<<endl;

    
    return 0;
}



// child parent/ method

// #include<bits/stdc++.h>
// using namespace std;

// bool dfs(vector<vector<int>> &gph, vector<int> &vis, int u = 0, int p = -1) {
//     vis[u] = 1;
    
//     for (auto &v: gph[u]) {
//         if (!vis[v]) 
//         if(dfs(gph, vis, v, u)) return true;
//         else if (v != p) 
//         return true;
//     }
//     return false;
// }

// int main() {
//     int n, m, x, y;
//     cin >> n >> m;
//     vector<vector<int>> gph(n);
//     vector<int> vis(n, 0);
//     for (int i = 0; i < m; i++) {
//         cin >> x >> y;
//         gph[x - 1].push_back(y - 1);
//         gph[y - 1].push_back(x - 1);
//     }
//     cout << (dfs(gph, vis) ? "Cycle Exists" : "Cycle doesn't exist");
//     return 0;
// }
