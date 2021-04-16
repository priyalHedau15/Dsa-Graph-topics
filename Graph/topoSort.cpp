// Kahn's Algo for topological sorting + detecting cycle by bfs
// for cycle detection , if there exists a cycle , in-degree of cycle causing node would never be zero  like -> 
// 0 ->1->2->3->4->1
// if cycle  doesn't  exist while looop would run n times thus cnt should b n s

#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<set>
using namespace std;


#define  vi vector<int>
#define pb push_back   
vector<int>in_deg; // in-deg -no. of incoming edges
vector<int> sortV;
// int cnt =0 
void kahn(vector<int>adj[],int n){
  queue<int>q;

  for(int i=1;i<=n;i++){ // v times
      if(in_deg[i]==0)
        q.push(i);
  }
  
   while(!q.empty()){ // 
       int current = q.front();
       sortV.pb(current);
       q.pop();
       for(auto child:adj[current]){ // E times
           in_deg[child]--;
           if(in_deg[child]==0)
             q.push(child);
       }
      //  cnt++;
       
   }
  //  if(cnt!=n) cout<<"cycle exists";
  
 
}


int main(){

    int n ,e;
    cin>>n>>e;

    vi adj[n+1];
    in_deg.assign(10001, 0);
    int a, b;
    for(int i=0;i<e;i++){
        cin>>a>>b;
        adj[a].pb(b);
        in_deg[b]+=1;
    }
   
   kahn(adj,  n);
   
   for(auto child:sortV)
      cout<<child<<" ";

      return 0;

}

// tC - O(V+E); outer for loop + inner for loop
  //sc - O(V)