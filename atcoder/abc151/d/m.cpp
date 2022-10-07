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

int main()
{

  int h, w;
  cin >> h >> w;

  vector<S> s(h);

  REP(i, h)
  {
    cin >> s[i];
  }

  int ans = -1;
  REP(i, h)
  {
    REP(j, w)
    {
      if (s[i][j] == '.')
      {
        queue<pair<P, int>> q;
        q.push(make_pair(make_pair(i, j), 0));

        int maxs = -1;

        vector<S> ss = s;
        ss[i][j] = '#';
        while (q.size() != 0)
        {
          P ww[4] = {make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1)};
          P b = q.front().first;
          int sc = q.front().second;
          q.pop();
          maxs = max(sc, maxs);
          REP(i, 4)
          {
            P ne = b + ww[i];
            if (0 <= ne.first && ne.first < h && 0 <= ne.second && ne.second < w)
            {
              if (ss[ne.first][ne.second] == '.')
              {
                ss[ne.first][ne.second] = '#';
                q.push(make_pair(ne, sc + 1));
              }
            }
          }
        }

        ans = max(maxs, ans);
      }
    }
  }

  cout << ans << endl;

  return 0;
}