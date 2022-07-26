#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

/* macro */
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
using V = vector<int>;
using VV = vector<vector<int>>;
using VVV = vector<vector<vector<int>>>;
using Vl = vector<long long>;
using VVl = vector<vector<long long>>;
using VVVl = vector<vector<vector<long long>>>;
using P = pair<int, int>;
using VP = vector<pair<int, int>>;
using VVP = vector<vector<pair<int, int>>>;
using S = string;
using VS = vector<string>;
using VVS = vector<vector<string>>;
using ll = long long;
constexpr int IINF = 1000000000 + 8;
constexpr long long LINF = 1000000000000000000LL + 8;
using mint = modint1000000007;

/* pair operator */
template <class X>
pair<X, X> operator+(pair<X, X> &ob1, pair<X, X> &ob2)
{
  pair<X, X> res;
  res.first = ob1.first + ob2.first;
  res.second = ob1.second + ob2.second;
  return res;
}

template <class X>
pair<X, X> operator-(pair<X, X> &ob1, pair<X, X> &ob2)
{
  pair<X, X> res;
  res.first = ob1.first - ob2.first;
  res.second = ob1.second - ob2.second;
  return res;
}

template <class X>
pair<X, X> operator*(pair<X, X> &ob1, pair<X, X> &ob2)
{
  pair<X, X> res;
  res.first = ob1.first * ob2.first;
  res.second = ob1.second * ob2.second;
  return res;
}

template <class X>
pair<X, X> operator/(pair<X, X> &ob1, pair<X, X> &ob2)
{
  pair<X, X> res;
  res.first = ob1.first / ob2.first;
  res.second = ob1.second / ob2.second;
  return res;
}
vector<S> c;
VV used;
P g;
P wa[4] = {make_pair(-1, 0), make_pair(0, -1), make_pair(1, 0), make_pair(0, 1)};
int h, w;

int dfs(P p, int num)
{

  if (p == g)
  {
    return num;
  }

  used[p.first][p.second] = 1;

  int res = -1;
  REP(i, 4)
  {
    P ne = p + wa[i];
    if (0 <= ne.first && ne.first < h && 0 <= ne.second && ne.second < w)
      if (used[ne.first][ne.second] == 0 && c[ne.first][ne.second] == '.')
      {
        res = max(dfs(ne, num + 1), res);
      }
  }
  used[p.first][p.second] = 0;

  return res;
}

int main()
{

  cin >> h >> w;

  c.resize(h);

  used.resize(h);

  REP(i, h)
  {
    used[i].resize(w);
    cin >> c[i];
  }
  int ans = -1;
  REP(i, h)
  {
    REP(j, w)
    {
      if (c[i][j] == '.')
      {
        g = make_pair(i, j);
        REP(k, 4)
        {
          P mm = g + wa[k];
          if (0 <= mm.first && mm.first < h && 0 <= mm.second && mm.second < w && c[mm.first][mm.second] == '.')
          {
            ans = max(ans, dfs(mm, 0));
          }
        }
      }
    }
  }
  if (ans + 1 >= 3)
  {
    cout << ans + 1 << endl;
  }
  else
  {
    cout << -1 << endl;
  }

  return 0;
}