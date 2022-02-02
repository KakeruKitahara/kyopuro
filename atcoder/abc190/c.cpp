#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep2(i, a, n) for (int i = a; i < n; i++)
#define P pair<int, int>
using namespace std;

int main()
{
  int n, m, k;
  cin >> n >> m;
  vector<int> a(m), b(m), dish(110, 0);
  rep(i, m) cin >> a[i] >> b[i];
  cin >> k;
  vector<int> c(k), d(k);
  rep(i, k) cin >> c[i] >> d[i];

  int maxs = -1;
  for (int s = 0; s < (1 << k); ++s)
  {
    int cnt = 0;
    rep(i, 110)
    {
      dish[i] = 0;
    }
    for (int i = 0; i < k; i++)
    {
      if ((s >> i) & 1){
        dish[c[i]]++;
      }
      else
        dish[d[i]]++;
    }
    rep(i, m)
    {
      if (dish[a[i]] > 0 && dish[b[i]] > 0)
        cnt++;
    }

    maxs = max(maxs, cnt);
  }
  cout << maxs;
  return 0;
}