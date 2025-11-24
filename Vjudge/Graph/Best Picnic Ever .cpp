
//https://vjudge.net/problem/lightoj-1111


#include <bits/stdc++.h>
using namespace std;
#define ll long long



const int N = 1e5+10;
vector<int> tree[N];
int persons[N];

bool visited[N];
int counters =0;


bool dfs(int vertex, int par,int person)
{

 if(persons[vertex] == 1)
 {
    person--;
}

if(person == 0){

   return true;
}

for(int child : tree[vertex])
{
    if(child == par) continue; 

    if (dfs(child, vertex, person)) {
        return true;
    } 

}


return false;


}





int main() {

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        int k,n,m;

        cin >> k >> n >> m;

        for(int i=1; i <= k; i++)
        {
            int position;
            cin >> position;
            persons[position] = 1;
        }


        for(int i = 1; i <= m; i++)
        {
           int v1,v2;
           cin >> v1 >> v2;
           tree[v2].push_back(v1);


       }


       int ctr = 0;

       for(int i=1; i <= n; i++)
       {
        bool checker = dfs(i,-1,k);
        if(checker == true)
        {
            ctr++;
        }

    }

    cout << ctr <<endl;

    for(int i =1; i <= n; i++)
    {
       tree[i].clear();
       persons[i]=0;
       visited[i]=false;
    }



}
}



