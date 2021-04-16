// #include<iostream>
// #include<vector>
// #include<queue>
// #include<cstring>
// #include<set>

// #include<string>
// #include<map>
// using namespace std;



// int timer  ;

// set<int> artiPoints;

// void dfs_artiPoints(int node , int par, vector<int>adj[], vector<int>&visited, vector<int>&in ,vector<int>&low){
//   visited[node] =1;
//   in[node] = low[node] = timer++;
//   int children=0;
//   for(auto child:adj[node]){
//       if(child==par) continue;
//       else if(visited[child]) // back edge
//           low[node] = min(low[node], in[child]);

//      else{ // forward edge or child isn't visited
//           dfs_artiPoints(child , node , adj, visited, in , low );
//           low[node] = min(low[node] , low[child]);

//           if(low[child] >=in[node] &&par!=-1)
//              artiPoints.insert(node);
            
//           children++;

//      }
//   }
//   if(par==-1 && children>1)
//      artiPoints.insert(node);
// }

// int main(){

//     int n ,e;
//     cin>>n;
//     string s;
//     map<string , int>  ind;
//     vector<string> city;
//     for(int i=1;i<=n;i++){
//        cin>>s;
//        ind[s] = i;
//        city.push_back(s);
//     }
       

//    cin>>e;
//     vector<int> adj[n+1];
//     vector<int>visited;
//     visited.assign(n+1, 0);
//     vector<int> in , low;
//     in.assign(n+1, 0);
//     low.assign(n+1, 0);
    
//     string a, b;
//     for(int i=0;i<e;i++){
//         cin>>a>>b;
//        adj[ind[a]].push_back( ind[b]);
//        adj[ind[b]].push_back( ind[a]);
        
//     }
   
//    dfs_artiPoints( 1, -1, adj, visited, in , low);

//     cout<<"city map #1: "<<artiPoints.size()<<"  found"<<"\n";

//    for(auto child:artiPoints){
//     cout<<child<<city[child-1]<<"\n";
//    }

// }

#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007

#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
// #define pq priority_queue<int>
#define lli long long int
#define endl '\n'


priority_queue<int > adj[100001];
vi visited;

vi ans;
void dfs(int node){
	visited[node] =1;
	ans.pb(node);
	for(auto child = adj[node].begin();child<adj[node].end();child++){

		if(!visited[adj[node][child])
		   dfs(child);
	}
}




int main(){
	int n , m ,k ,x ,y;
	cin>>n>>m>>k;

    visited.resize(n+1, 0);
    REP(i,m) cin>>x>>y , adj[x].push_back(y) , adj[y].push_back(x);

    int count=0;
	REP(i,n){
		if(!visited[i]){
			count++;
			dfs(i);
		}
	}
    
	if(count>k)
	   cout<<"-1";
	else{
REP(i,n){
		cout<<ans[i]<<" ";
	 }
	}
     
return 0;

}
