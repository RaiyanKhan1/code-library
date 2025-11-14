
// https://vjudge.net/problem/cses-1667

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5+5;
const int inf = 1e9;
vector <int> tree[N];


int visited[N];


int main()
{

  int n,m;
  cin >>n >> m;

  

  for(int i =0; i < m; i++)
  {
     int u; cin >> u;
     int v; cin >> v;

     tree[u].push_back(v);
     tree[v].push_back(u);
     
  }


  queue<int> list;
  vector <int> dst(n+1,inf);

  list.push(1);
  visited[1] = true;

   

  dst[1] = 0;
  vector <int> par(N);


  

  
  while(!list.empty())
  {

    int current = list.front();
    
    list.pop();

      for(auto a : tree[current])
      {
        if(!visited[a])
        {
          par[a] = current;
          dst[a] = dst[current]+1;
          list.push(a);
          visited[a] = true;
        }
        
        
      }
  }

  vector <int> pathd;
  
  if(dst[n] != inf)
  {
   cout << dst[n]+1 <<endl;
   int path = n;
   while(path!=0)
   {
    pathd.push_back(path);
    path = par[path] ;
   }

   reverse(pathd.begin(),pathd.end());

   for(auto i : pathd)
   {
    cout << i << " ";
   }
  }
  else{
    cout << "IMPOSSIBLE" << '\n';
  }
 

  return 0;

   

      
}

