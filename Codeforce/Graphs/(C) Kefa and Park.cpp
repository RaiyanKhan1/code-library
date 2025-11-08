
https://codeforces.com/problemset/problem/580/C



#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5+10;
vector<int> tree[N];
int counter = 0;
int k;

void dfs(int vertex, int par, const vector<int>& a, int c) {
    if (a[vertex] == 1)
        c++;
    else
        c = 0;

    if (c > k)
        return;

    bool isLeaf = true;

    for (int child : tree[vertex]) {
        if (child == par) continue;
        dfs(child, vertex, a, c);
        isLeaf = false;
    }

    if (isLeaf)
        counter++;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n >> k;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 0; i < n - 1; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        tree[v1].push_back(v2);
        tree[v2].push_back(v1); 
    }

    dfs(1, 0, a, 0);
    cout << counter << '\n';
}