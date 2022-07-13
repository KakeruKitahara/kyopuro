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
  int n, m;
  cin >> n >> m;
  VV ed(n);
  REP(i, m)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    ed[a].push_back(b);
    ed[b].push_back(a);
  }

  queue<pair<int, int>> q;
  V nu;
  q.push(make_pair(0, -1));

  V jd(n);
  jd[0] = 1;

  V ans(n, -1);

  while (q.size() != 0)
  {
    pair<int, int> v = q.front();
    q.pop();
    REP(i, ed[v.first].size())
    {
      if (jd[ed[v.first][i]] == 0)
      {
        ans[ed[v.first][i]] = v.first;
        jd[ed[v.first][i]] = 1;
        q.push(make_pair(ed[v.first][i], v.first));
      }
    }
  }

  REP2(i, 1, n)
  {
    if (ans[i] == -1)
    {
      cout << "No" << endl;
    }
  }
  cout << "Yes" << endl;

  REP2(i, 1, n)
  {
    cout << ans[i] + 1 << endl;
  }

  return 0;
}