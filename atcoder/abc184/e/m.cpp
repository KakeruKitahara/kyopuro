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
  vector<S> m(h);
  VVP ae(26);
  V al(26);
  P s, g;
  REP(i, h)
  {
    cin >> m[i];
    REP(j, w)
    {
      if (0 <= m[i][j] - 'a' && m[i][j] - 'a' < 26)
      {
        ae[m[i][j] - 'a'].push_back(make_pair(j, i));
        al[m[i][j] - 'a'] = 1;
      }
      if (m[i][j] == 'S')
      {
        s = make_pair(j, i);
      }
      if (m[i][j] == 'G')
      {
        g = make_pair(j, i);
      }
    }
  }

  queue<pair<P, int>> q;
  q.push(make_pair(s, 0));
  VV used(h, V(w));
  P wa[4] = {make_pair(-1, 0), make_pair(0, -1), make_pair(1, 0), make_pair(0, 1)};
  int ans = -1;
  while (q.size() != 0)
  {
    P p = q.front().first;
    int num = q.front().second;
    q.pop();

    if (m[p.second][p.first] == 'G')
    {
      ans = num;
      break;
    }

    if (0 <= m[p.second][p.first] - 'a' && m[p.second][p.first] - 'a' < 26)
    {
      if (al[m[p.second][p.first] - 'a'] == 1 && ae[m[p.second][p.first] - 'a'].size() != 1)
      {
        REP(j, ae[m[p.second][p.first] - 'a'].size())
        {
          if (p != ae[m[p.second][p.first] - 'a'][j])
          {
            q.push(make_pair(ae[m[p.second][p.first] - 'a'][j], num + 1));
            used[ae[m[p.second][p.first] - 'a'][j].second][ae[m[p.second][p.first] - 'a'][j].first] = 1;
          }
        }
        al[m[p.second][p.first] - 'a'] = 0;
      }
    }

    REP(i, 4)
    {
      P ne = wa[i] + p;
      if (0 <= ne.first && ne.first < w && 0 <= ne.second && ne.second < h)
      {
        if (m[ne.second][ne.first] != '#' && used[ne.second][ne.first] == 0)
        {
          used[ne.second][ne.first] = 1;
          q.push(make_pair(ne, num + 1));
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}