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

int ans;
vector<S> s;
VV used;
int h, w2;

void dfs(P p)
{
  used[p.first][p.second] = 1;

  P w[4] = {make_pair(-1, 0), make_pair(0, 1), make_pair(1, 0), make_pair(0, -1)};

  REP(i, 4)
  {

    P n = p + w[i];
    if (0 <= n.first && n.first < h && 0 <= n.second && n.second < w2)
    {
      if (used[n.first][n.second] == 0 && s[n.first][n.second] == '#')
      {
        dfs(n);
      }
    }
  }

  V c(4);
  int c2 = 0;
  REP(i, 4)
  {
    P n = p + w[i];
    if (s[n.first][n.second] == '.')
    {
      c[i] = 1;
      c2++;
    }
  }

  if (c2 == 2)
  {
    if (c[0] == 1 && c[1] == 0 && c[2] == 1 && c[3] == 0)
    {
      c2 = 0;
    }
    else if (c[0] == 0 && c[1] == 1 && c[2] == 0 && c[3] == 1)
    {
      c2 = 0;
    }
  }

  if (c2 == 4)
  {
    ans += c2;
  }
  else
  {
    ans += max(c2 - 1, 0);
  }
}

int main()
{
  cin >> h >> w2;
  s.resize(h);
  used.resize(h);
  REP(i, h)
  {
    used[i].resize(w2);
    cin >> s[i];
  }

  ans = 0;
  REP(i, h)
  {
    REP(j, w2)
    {
      if (s[i][j] == '#')
      {
        dfs(make_pair(i, j));

        cout << ans << endl;
        return 0;
      }
    }
  }

  return 0;
}