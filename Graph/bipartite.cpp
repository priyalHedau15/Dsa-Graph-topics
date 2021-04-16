#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define vi vector<int>
#define pb push_back

vi visited;
vi adj[6];
vi color;

bool dfs(int v, int c)
{
  visited[v] = 1;
  color[v] = c;

  for (auto child : adj[v])
  {
    if (visited[child] == 0)
    {
      bool res = dfs(child, c ^ 1);
      if (res == false)
        return false;
    }

    else if (color[child] == color[v]) // if edge connects the node with the child of same color , then return false
      return false;
  }

  return true;
}

int main()
{
  int n ;
  cin>>n;
  int a, b;
  color.resize(n+1,0);
  visited.resize(n+1, 0);
  for (int i = 1; i <= n; i++)
  {
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  if (dfs(1, 0) == true)
    cout << "True"
         << "\n";
  else
    cout << "False"
         << "\n";

  return 0;
}