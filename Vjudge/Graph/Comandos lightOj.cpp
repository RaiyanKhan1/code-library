//https://lightoj.com/problem/commandos
/*
   - track lowest distance from start
   - track lowest distance from end
   - sum them togather
   - the maximum sum is the ans

*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5+10;
vector<int> tree[N];

int visited[N];
int dst[N];
int par[N];

int visited2[N];
int dst2[N];
int par2[N];


int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {

     for(int i = 0; i < N; i++)
     {
       tree[i].clear();
       visited[i]=0;
       dst[i]=0;
       par[i]=0;

       visited2[i]=0;
       dst2[i]=0;
       par2[i]=0;
   }


   int n,m;
   cin >> n >> m;

   for(int i = 0; i < m; i++)
   {
    int v1,v2;
    cin >> v1 >> v2;
    tree[v1].push_back(v2);
    tree[v2].push_back(v1);
}

int start,end;
cin >> start >> end;



queue <int> q;

dst[start] = 0;

q.push(start);
visited[start] = true;


while(!q.empty())
{
  int u = q.front();
  q.pop();

  for(auto i : tree[u])
  {
     if(!visited[i])
     {
        q.push(i);
        par[i] = u; 
        visited[i] = true;
        dst[i] = dst[u] + 1;          
    }
}

}


while(!q.empty()) q.pop();

dst2[end] = 0;

q.push(end);
visited2[end] = true;




while(!q.empty())
{
  int u = q.front();
  q.pop();

  for(auto i : tree[u])
  {
     if(!visited2[i])
     {
       q.push(i);
       par2[i] = u; 
       visited2[i] = true;
       dst2[i] = dst2[u] + 1;          
   }
}

}

int lowestDst = -1e7;

for(int i=0; i < n;i++)
{
    dst[i] += dst2[i];
    lowestDst = max(lowestDst, dst[i]);

}

cout << lowestDst << endl;










}



}


