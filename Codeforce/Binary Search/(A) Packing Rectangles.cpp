
https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A


#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll w,h,n;

bool isValid(ll x)
{
  

  return n <= (x/w)*(x/h);
}


int main()
{

  
  cin >> w >> h >> n;

  ll l = 0;
  ll r = 1;

  while(isValid(r) == false)
  {
    r *=2;
  }

  ll mid = 0;


  while(l < r)
  {
     mid = l+ (r-l)/2 ;

    if(isValid(mid) == true)
    {
      r = mid;
      
    }
    else if(isValid(mid) == false){
      l = mid+1;
      
    }
  }

  cout << l <<endl;




  
}
  


  


