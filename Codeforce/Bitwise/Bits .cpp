//https://codeforces.com/problemset/problem/484/A


#include <bits/stdc++.h>
using namespace std;
#define ll long long



int main()
{

  ll t;
  cin >>t;

  while(t--)
  {

    ll l,r;
    cin >> l >> r;

    ll ans=l;
    int position = 0;

    while(true)
    {

         
         ll mask = (1ll << position); 
         ll temp = ans | mask; 
         if(temp > r)break;
         ans = temp;
         position++;

    }

    cout << ans << endl;

     
  }

   

      
}

