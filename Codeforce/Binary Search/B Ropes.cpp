https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B


#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m;
vector <ll> a;

bool isValid(double x)
{
  int ans = 0;

  for(int i=0; i < n; i++)
  {
      ans += a[i]/x;
  }
 
 if(ans >= m)
 {
  return true;
 }
 else{
  return false;
 }

  
}


int main()
{

  
  cin >> n >> m;

  

  for(int i = 0; i < n; i++)
  {
     int temp;
     cin >> temp;
     a.push_back(temp);
  }

  sort(a.begin(),a.end());

  double l = 0;
  double r = a[n-1];

  double mid = 0;

  int ctr = 100;


  while(ctr--)
  {
     mid = l+(r-l)/2 ;

    if(isValid(mid) == true)
    {
      l = mid;
      
      
    }
    else if(isValid(mid) == false){
      
      r = mid;
    }
  }

  cout << setprecision(16) << l << '\n';




  
}
  


  


