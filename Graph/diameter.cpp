// calculating diameter of tree which is the longest distance bet two nodes , 
// first we'll run dfs to get farthest node(X) from root , 
// then second dfs to calculate distance between X and another farthest node, 
// which we'll give us diameter 



#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;


#define  vi vector<int>
#define pb push_back   
#define REP(i , n) for(i=0;i<n;i++)

vi visited ;


int maxDis , maxNode;

void dfs(vi adj[] , int node, int d){
    visited[node] = 1;
    if(d>maxDis ) maxDis = d , maxNode = node;

     for(auto child:adj[node]){
         if(!visited[child])
              dfs(adj , child , d+1);
     }
}


int main(){

    int no;
    cin>>no;
     
      int i , a, b;
      vi adj[no+1];
      
      visited = vi(no,0);
     REP( i , no-1){
         cin>>a>>b;
         
         adj[a].pb(b) , adj[b].pb(a);

     }
     
         maxDis =-1 ;
     dfs(adj , 1 , 0);

     
      
       for(int i =1;i<=no;i++)
       visited[i] =0;

       dfs(adj , maxNode , 0);

       cout<<maxDis;



    return 0;

}