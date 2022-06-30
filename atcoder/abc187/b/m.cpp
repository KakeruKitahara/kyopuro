#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep2(i, a, n) for (int i = a; i < n; i++)
#define P pair<int, int>
using namespace std;

int main()
{
  int n, cnt = 0;
  cin >> n;
  P a[n];
  rep(i, n)
  {
    cin >> a[i].first >> a[i].second;
  }

  rep(i, n)
  {
    rep2(j, i + 1, n)
    {
      if (-1 <= double(a[i].second - a[j].second) / (a[i].first - a[j].first) && double(a[i].second - a[j].second) / (a[i].first - a[j].first) <= 1)
      {
        cnt++;
      }
    }
  }
  cout << cnt;
  return 0;
}