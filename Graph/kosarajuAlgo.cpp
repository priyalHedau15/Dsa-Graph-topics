// for counting SCC's in a directed graph using two dfs 
// first dfs -> to calculate out-time of node 
// now the node with highest out-time will have in-degree 0 


#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define endl '\n'
 
using namespace std;
vi ar[1001]; // adjacency list 
vi tr[1001]; // transpose
 
vi order;// store node in increasing order of out-time
vi SCC;
 
int vis[1001];
 
void dfs(int node)
{
	vis[node] = 1;
 
	for(int child : ar[node])
	if(vis[child] == 0)
	dfs(child);
 
	order.pb(node);
}
 
void dfs1(int node)
{
	vis[node] = 1;
 
	for(int child : tr[node])
	if(vis[child] == 0)
	dfs1(child);
 
	SCC.pb(node);
}
 
int main()
{
	int n , a , b , m , t;
	cin>>t;
 
	while(t--)
	{
		cin>>n>>m;
		REP(i , n) ar[i].clear() , tr[i].clear() , vis[i] = 0;
		order.clear();
 
		REP(i , m)
		{
			cin>>a>>b;
			ar[a].pb(b);
			tr[b].pb(a);
		}
 
		REP(i , n)
		if(vis[i] == 0) dfs(i);
 
		REP(i , n) vis[i] = 0;
 
		REP(i , n)
		if(vis[order[n-i]] == 0) // we'll start with  vertex  having greatest out time 
		{
			SCC.clear();
			dfs1(order[n - i]);
 
			cout<<"dfs1() called from "<<order[n-i]<<" and printing SCC"<<endl;
			for(int node : SCC)
			cout<<node<<" ";
			cout<<endl;
		}
	}
}
 