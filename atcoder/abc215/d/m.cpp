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
  int n, m;
  cin >> n >> m;
  V a(n);
  REP(i, n)
  {
    cin >> a[i];
  }

  set<int> so;

  REP(i, n)
  {
    vector<P> prime;
    for (int ind = 2; ind * ind <= a[i]; ind++)
    {
      if (a[i] % ind != 0)
        continue;
      int ex = 0;
      while (a[i] % ind == 0)
      {
        ex++;
        a[i] /= ind;
      }
      prime.push_back({ind, ex});
    }

    if (a[i] != 1)
      prime.push_back({a[i], 1});

    REP(j, prime.size())
    {
      so.insert(prime[j].first);
    }
  }

  V s;
  for (int k : so)
  {
    s.push_back(k);
  }
  V ans;

  REP2(i, 1, m + 1)
  {
    int ff = 0;
    REP(j, s.size())
    {
      if (i % s[j] == 0)
      {
        ff = 1;
        break;
      }
    }

    if (ff == 1)
    {
      continue;
    }
    ans.push_back(i);
  }

  cout << ans.size() << endl;
  REP(i, ans.size())
  {
    cout << ans[i] << endl;
  }

  return 0;
}