#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define P pair<int, int>
using namespace std;

int main()
{
  int a, b, sum1 = 0, sum2 = 0;
  cin >> a >> b;

  rep(i, 3){
    sum1 += a% 10;
    a /=10; 
  }

  rep(i, 3)
  {
    sum2 += b % 10;
    b /= 10;
  }

  if(sum1<sum2){
    cout << sum2;
  }
  else{
    cout << sum1;
  }
  return 0;
}