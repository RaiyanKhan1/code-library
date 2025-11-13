
// https://vjudge.net/problem/aizu-alds1_11_c

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5+5;
const int inf = 1e9;
vector <int> tree[N];

int nodes[N];
int visited[N];


int main()
{

  int n;
  cin >>n;

  int t = n;

  while(t--)
  {
     int u; cin >> u;
     int k; cin >> k;
     for(int i = 0; i < k; i++)
     {
      int temp;
      cin >> temp;

      tree[u].push_back(temp);

     }
  }


  queue<int> list;
  vector <int> dst(n+1,inf);

  list.push(1);
  visited[1] = true;

   

  dst[1] = 0;



  nodes[1] = 1;

  
  while(!list.empty())
  {

    int current = list.front();
    
    list.pop();

      for(auto a : tree[current])
      {
        if(!visited[a])
        {
          nodes[a] = a;
          dst[a] = dst[current]+1;
          list.push(a);
          visited[a] = true;
        }
        
        
      }
  }

  for(int i = 1; i <= n; i++)
  {
    cout << i << ' ' << (dst[i] == inf ? -1 : dst[i]) << '\n';
  }
  return 0;

   

      
}

