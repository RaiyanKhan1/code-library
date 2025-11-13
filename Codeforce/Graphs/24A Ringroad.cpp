// https://codeforces.com/problemset/problem/24/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5+10;
vector<pair<int,int>> tree[N];

bool visited[N];
int counters =0;
int cnt = 0;


void dfs(int vertex, int par)
{
  visited[vertex] = true;
 for(auto edge : tree[vertex])
 {
   int child = edge.first;
   int w = edge.second;

  if(!visited[child])
  {
    cnt+= w;
   dfs(child,vertex); 
  }
   else if(child == 1 && child != par)
  {
    cnt += w;
  }

}



}


int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL);

  int t;
  cin >> t;
  
  int sum = 0;

  for(int i = 0; i < t; i++)
  {
   int v1,v2,w;
   cin >> v1 >> v2 >> w;
   tree[v1].push_back({v2,0});
   tree[v2].push_back({v1,w});

   sum += w;

 }






 dfs(1,0);

 cout << min(cnt,sum-cnt);

}


