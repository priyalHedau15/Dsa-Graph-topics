#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

#define  vi vector<int>
#define pb push_back   

class edge{
    public:
    int a , b, w;

};

edge arr[1000];
int par[1000] ;

bool comp(edge a , edge b){
    if(a.w<b.w) return true;

    return false;
}

int find(int a){
 if(par[a]==-1)return a;

 return par[a] = find(par[a]);

}

void merge(int a , int b){

    par[b] =a;
}


int main(){
  
  int a, b, w;

  int n , m;
  cin>>n>>m;
int sum=0;

for(int i=1;i<=n;i++) par[i]=-1;

  for(int i=0;i<m;i++){
      cin>>arr[i].a>>arr[i].b>>arr[i].w;
  }
  
   sort(arr, arr+m , comp);

   for(int i=0;i<m;i++){
       int par_a  = find(arr[i].a);
       int par_b  = find(arr[i].b);

       if(par_a!=par_b){
           sum+=arr[i].w;
           merge(arr[i].a, arr[i].b);
       }
   }
 
    cout<<sum;
  

  return 0;

}

// overall time complexity is O(ElogE);

//  Sorting of edges takes O(ELogE)

