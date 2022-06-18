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
  V h, w;
  vector<vector<S>> r;
  vector<S> s;
  while (1)
  {
    int h2, w2;
    cin >> h2 >> w2;
    if (h2 == 0 && h2 == 0)
    {
      break;
    }
    h.push_back(h2);
    w.push_back(w2);
    vector<S> r2;
    REP(j, h2)
    {
      S q;
      cin >> q;
      r2.push_back(q);
    }
    r.push_back(r2);
    S s2;
    cin >> s2;
    s.push_back(s2);
  }

  REP(i, h.size())
  {
    P p = make_pair(0, 0);
    int ans = 0;
    REP(l, s[i].size())
    {
      int f = 0;
      REP(j, h[i])
      {
        REP(k, w[i])
        {
          if (s[i][l] == r[i][j][k])
          {
            ans += abs(j - p.first) + abs(k - p.second);
            p = make_pair(j, k);
            f = 1;
            break;
          }
          if (f == 1)
          {
            break;
          }
        }
        if (f == 1)
        {
          break;
        }
      }
      ans++;
    }

    cout << ans << endl;
  }

  return 0;
}