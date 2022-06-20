#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using V = vector<int>;
using Vl = vector<long long>;
using VV = vector<vector<int>>;
using VVl = vector<vector<long long>>;
using P = pair<int, int>;
using Pl = pair<long long, long long>;
using S = string;
using ll = long long;
constexpr int IINF = 1000000000 + 8;
constexpr long long LINF = 1000000000000000000LL + 8;
using mint = modint1000000007;

int main()
{
  int n;
  cin >> n;
  V a(n);
  REP(i, n)
  {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  int ans = 0;
  REP(i, n)
  {
    vector<int> res;

    for (int j = 1; j * j <= a[i]; ++j)
    {
      if (a[i] % j != 0)
        continue;

      res.push_back(j);

      if (a[i] / j != j)
        res.push_back(a[i] / j);
    }

    int f = 0;
    REP(j, res.size())
    {
      auto it = lower_bound(a.begin(), a.end(), res[j]);
      auto it2 = upper_bound(a.begin(), a.end(), res[j]);
      if (*it == res[j])
      {
        f += it2 - it;
      }
    }
    if (f == 1)
    {
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}