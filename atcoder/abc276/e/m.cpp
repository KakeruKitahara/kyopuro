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

VS c;
int h, w;

void dfs(P p, int d)
{

  if (c[p.first][p.second] != 'S')
  {
    c[p.first][p.second] = '#';
  }

  P w2[4] = {make_pair(1, 0), make_pair(0, 1), make_pair(-1, 0), make_pair(0, -1)};

  REP(i, 4)
  {
    P next = p + w2[i];

    if (0 <= next.first && next.first < h && 0 <= next.second && next.second < w)
    {
      if (c[next.first][next.second] == '.')
      {
        dfs(next, d + 1);
      }
      else if (c[next.first][next.second] == 'S')
      {
        if (d + 1 >= 4)
        {
          cout << "Yes" << endl;
          exit(0);
        }
      }
    }
  }


}

int main()
{

  cin >> h >> w;
  c.resize(h);
  P s;
  REP(i, h)
  {
    cin >> c[i];
    REP(j, w)
    {
      if (c[i][j] == 'S')
      {
        s = make_pair(i, j);
      }
    }
  }

  dfs(make_pair(s.first, s.second), 0);

  cout << "No" << endl;

  return 0;
}