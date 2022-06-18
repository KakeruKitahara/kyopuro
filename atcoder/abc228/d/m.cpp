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
  int q;
  cin >> q;
  Vl t(q), x(q);
  REP(i, q)
  {
    cin >> t[i] >> x[i];
  }

  set<int> z;
  Vl b(1048576, -1);

  REP(i, 1048576)
  {
    z.insert(i);
  }

  REP(i, q)
  {
    if (t[i] == 1)
    {
      auto it = z.lower_bound(x[i] % 1048576);
      if (it == z.end())
      {
        auto it2 = z.lower_bound(0);
        it = it2;
      }
      b[*it] = x[i];
      z.erase(it);
    }
    else
    {
      cout << b[x[i] % 1048576] << endl;
    }
  }

  return 0;
}