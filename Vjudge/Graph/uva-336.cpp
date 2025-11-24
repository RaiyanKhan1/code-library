//https://vjudge.net/problem/uva-336

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5+5;
const int inf = 1e9;
vector <int> tree[N];
int visited[N];
int lvl[N];

int main()
{
  int ctr = 1;
  

  while(true)
  {
  int n;
  cin >> n;

  if(n==0)
  {
    break;
  }

  set <int> nodes;
  nodes.clear();
  

  for(int i=0; i <N; i++)
   {
    tree[i].clear();
   }
  

  for(int i =0; i < n; i++)
  {
   int u; cin >> u;
   int v; cin >> v;
   nodes.insert(u);
   nodes.insert(v);
   tree[u].push_back(v);
   tree[v].push_back(u);

 }
 
 int q1 =1;
 int q2 =2;


 while(true)
 {

   cin >> q1;
   cin >> q2;

   if(q1 == 0 && q2 == 0)
   {
    break;
   }


   queue<int> list;
   vector <int> dst(N,inf);

   for(int i=0; i <N; i++)
   {
    dst[i] = inf;
    visited[i] = false;
    lvl[i] = 0;
   }


   visited[q1] = true;

   list.push(q1);

   dst[q1] = 0;

   
    if(nodes.find(q1) != nodes.end())
    {
      lvl[0] = 1;
    }
    else{
      lvl[0] = 0;
    }
   
   

   while(!list.empty())
   {

    int current = list.front();
    
    list.pop();

    for(auto a : tree[current])
    {
      if(!visited[a])
      {

        dst[a] = dst[current]+1;
        list.push(a);
        visited[a] = true;
        lvl[dst[a]]++;
      }


    }
  }

  int sum = 0;

  for(int i =0; i<=q2;i++)
  {
   sum += lvl[i];
 }


 cout << "Case " << ctr  <<": "<< (nodes.size())-sum <<" nodes not reachable from node " <<q1 << " with TTL = " << q2 <<'.' << endl;
 ctr++;
}




}

}

