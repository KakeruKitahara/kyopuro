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
  V l(n), r(n);
  set<P> s;
  REP(i, n)
  {
    cin >> l[i] >> r[i];
    s.insert(make_pair(l[i], i));
  }

  for (auto p = s.begin(); p != s.end();)
  {
    auto it = s.lower_bound(make_pair(r[p->second] + 1, 0));

    it--;
    if (it == p)
    {
      p++;
      continue;
    }

    it++;
    int maxs = -1;
    int cnt = 0;

    for (auto p2 = p; p2 != it; p2++)
    {
      maxs = max(maxs, r[p2->second]);
      cnt++;
    }

    r[p->second] = maxs;
    p++;

    REP(i, cnt - 1)
    {
      p = s.erase(p);
    }
    p--;
  }

  for (P a : s)
  {
    cout << a.first << " " << r[a.second] << endl;
  }

  return 0;
}