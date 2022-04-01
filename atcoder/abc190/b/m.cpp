#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep2(i, a, n) for (int i = a; i < n; i++)
#define P pair<int, int>
using namespace std;

int main()
{
  int n, f = 0;
  long long  s, d;
  cin >> n >> s >> d;
  vector<pair<long long, long long>> p(n);
  rep(i, n)cin >> p[i].first>>p[i].second;

  rep(i, n){
    if(p[i].first < s && p[i].second > d){
      f = 1;
      break;

    }
  }
  if(f == 1){
    cout << "Yes";
  }
  else{
    cout << "No";
  }



  return 0;
}