//Dijkstra’s algorithm is very similar to Prim’s algorithm for minimum spanning tree. Like Prim’s MST, we generate a SPT (shortest path tree) with given source as root. We maintain two sets, one set contains vertices included in shortest path tree, other set includes vertices not yet included in shortest path tree. At every step of the algorithm, we find a vertex which is in the other set (set of not yet included) and has a minimum distance from the source.


#include<iostream>
#include<set>
#include<vector>

using namespace std;
#define inf 100000

vector<pair<int,int>> adj[1001];



void dijkstra(int n){
    set<pair<int, int>> setn;//pair<wt , node>
    vector<int>dist(1001, inf);
    setn.insert(make_pair(0,1));
    dist[1] =0;
    
    while(!setn.empty()){
      pair<int, int>temp  = *(setn.begin());
      int u = temp.second;
       setn.erase(setn.begin());

       for(auto edge :adj[u]){
           int v = edge.first;
           int wt = edge.second;

           if(dist[v]>dist[u]+wt){
               if(dist[v]!=inf)
                 setn.erase(setn.find(make_pair(dist[v], v)));
                
                dist[v] = dist[u] +wt;
                setn.insert(make_pair(dist[v], v));

           }
       }
      

    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
}

int main(){
    int n , e;
    cin>>n>>e;
    int a, b, w;

    

    while(e--){
        cin>>a>>b>>w;
        adj[a].push_back({b,w});// undirected graph
        adj[b].push_back({a,w});

    }

    
    dijkstra(n);
    

    return 0;
}

// tc = Elog V  since we r visiting every node and edge , log  bcoz of set
// sc = O(E+V) to store graph and O(V) for set
// we can also use priority qu 
// 