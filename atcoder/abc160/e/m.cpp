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
  int x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  Vl p(a), q(b), r(c);

  REP(i, a)
  {
    cin >> p[i];
  }
  REP(i, b)
  {
    cin >> q[i];
  }
  REP(i, c)
  {
    cin >> r[i];
  }

  sort(p.begin(), p.end());
  sort(q.begin(), q.end());
  sort(r.rbegin(), r.rend());
  ll ans = 0;
  REP(i, x)
  {
    ans += p[a - i - 1];
  }

  REP(i, y)
  {
    ans += q[b - i - 1];
  }

  int mx = a - x, my = b - y;

  REP(i, c)
  {
    auto itx = lower_bound(p.begin(), p.end(), r[i]);
    auto ity = lower_bound(q.begin(), q.end(), r[i]);

    if (itx - p.begin() > mx && ity - q.begin() > my)
    {
      ll sax = r[i] - p[mx], say = r[i] - q[my];
      if (sax > say)
      {
        ans += sax;
        mx++;
      }
      else
      {
        ans += say;
        my++;
      }
    }
    else if (itx - p.begin() > mx)
    {
      ll sax = r[i] - p[mx];
      ans += sax;
      mx++;
    }
    else if (ity - q.begin() > my)
    {
      ll say = r[i] - q[my];
      ans += say;
      my++;
    }
  }

  cout << ans << endl;

  return 0;
}