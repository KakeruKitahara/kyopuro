#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using V = vector<int>;
using VV = vector<vector<int>>;
using P = pair<int, int>;
using S = string;
using ll = long long;
constexpr int INF = 1000000000 + 8;
using mint = modint1000000007;

int main()
{
  int h, w, c, q;
  cin >> h >> w >> c >> q;
  vector<ll> cv(q);
  V nv(q), tv(q);

  REP(i, q)
  {
    cin >> tv[i] >> nv[i] >> cv[i];
  }

  // int型はsetだとfind関数はできない．
  unordered_set<int> row, col;
  vector<ll> color(c + 1);

  REPR(i, q)
  {
    if (tv[i] == 1)
    {
      if (row.find(nv[i]) == row.end())
      {
        color[cv[i]] += (ll)w - col.size();
        row.insert(nv[i]);
      }
    }
    else if (tv[i] == 2)
    {
      if (col.find(nv[i]) == col.end())
      {
        color[cv[i]] += (ll)h - row.size();
        col.insert(nv[i]);
      }
    }
  }

  REP2(i, 1, c + 1)
  {
    cout << color[i] << " ";
  }
  puts("");

  return 0;
}