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
  int n, m, q;
  cin >> n >> m >> q;
  V w(n);
  V v(n);
  vector<P> vp(n);
  REP(i, n)
  {
    cin >> w[i] >> v[i];
    vp[i].first = v[i];
    vp[i].second = i;
  }
  V x(m);
  REP(i, m)
  {
    cin >> x[i];
  }
  vector<P> lr(q);
  REP(i, q)
  {
    cin >> lr[i].first >> lr[i].second;
    lr[i].first--;
    lr[i].second--;
  }

  vector<vector<P>> t(n, vector<P>(m));

  REP(i, n)
  {
    REP(j, m)
    {
      t[i][j].first = x[j] - w[i];
      t[i][j].second = j;
    }
    sort(t[i].begin(), t[i].end());
  }

  sort(vp.rbegin(), vp.rend());

  V o;
  REP(i, vp.size())
  {
    o.push_back(vp[i].second);
  }

  REP(i, q)
  {
    V st;
    int ans = 0;
    REP2(j, lr[i].first, lr[i].second + 1)
    {
      st.push_back(j);
    }

    REP(j, n)
    {
      REP(k, m)
      {
        if (t[o[j]][k].first >= 0)
        {
          int f = 0;
          REP(l, st.size())
          {
            if (st[l] == t[o[j]][k].second)
            {
              f = 1;
              break;
            }
          }
          if (f == 0)
          {
            ans += v[o[j]];
            st.push_back(t[o[j]][k].second);
            break;
          }
        }
      }
    }

    cout << ans << endl;
  }
  return 0;
}