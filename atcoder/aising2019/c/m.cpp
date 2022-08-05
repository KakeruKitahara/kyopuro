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

VV used;
int h, w;
P dfs(P p)
{
  int nc;
  P sum = make_pair(0, 0);
  if (used[p.first][p.second] == 2) // 白
  {
    sum.first = 1;
    nc = 1;
  }
  else if (used[p.first][p.second] == 1)
  {
    nc = 2;
    sum.second = 1;
  }

  used[p.first][p.second] = 0;
  P wa[4] = {make_pair(0, 1), make_pair(1, 0), make_pair(0, -1), make_pair(-1, 0)};

  REP(i, 4)
  {
    P ne = p + wa[i];
    if (0 <= ne.first && ne.first < h && 0 <= ne.second && ne.second < w)
    {
      if (used[ne.first][ne.second] == nc)
      {
        P t = dfs(ne);
        sum = sum + t;
      }
    }
  }

  return sum;
}

int main()
{

  cin >> h >> w;
  VS s(h);
  REP(i, h)
  {
    cin >> s[i];
  }

  used.resize(h);
  REP(i, h)
  {
    used[i].resize(w);
  }

  REP(i, h)
  {
    REP(j, w)
    {
      if (s[i][j] == '.')
      {
        used[i][j] = 2;
      }
      else
      {
        used[i][j] = 1;
      }
    }
  }
  vector<pair<ll, ll>> v;
  REP(i, h)
  {
    REP(j, w)
    {
      if (used[i][j] == 1)
      {
        v.push_back(dfs(make_pair(i, j)));
      }
    }
  }

  ll ans = 0;
  REP(i, v.size())
  {
    ans += v[i].first * v[i].second;
  }

  cout << ans << endl;

  return 0;
}