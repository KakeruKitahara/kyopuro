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
constexpr int INF = 1000000000 + 8;
using mint = modint1000000007;

int main()
{
  int h, w;
  cin >> h >> w;

  VV c(h, V(w));
  set<int> a = {1, 2, 3, 4, 5};

  REP(i, h)
  {
    REP(j, w)
    {
      char t;
      cin >> t;
      if (t == '.')
      {
        c[i][j] = 0;
      }
      else
      {
        c[i][j] = t - '0';
      }
    }
  }

  REP(i, h)
  {
    REP(j, w)
    {
      set<int> b;
      set<int> r;
      vector<P> p = {make_pair(i - 1, j), make_pair(i + 1, j), make_pair(i, j - 1), make_pair(i, j + 1)};
      REP(k, 4)
      {
        if (!(p[k].first < 0 || p[k].first > h - 1 || p[k].second < 0 || p[k].second > w - 1))
        {
          if (c[p[k].first][p[k].second] != 0)
          {
            b.insert(c[p[k].first][p[k].second]);
          }
        }
      }
      if (c[i][j] == 0)
      {
        set_difference(a.begin(), a.end(),
                       b.begin(), b.end(),
                       std::inserter(r, r.end()));
        c[i][j] = *(r.begin());
      }
    }
  }

  REP(i, h)
  {
    REP(j, w)
    {
      cout << c[i][j];
    }
    cout << endl;
  }
  return 0;
}