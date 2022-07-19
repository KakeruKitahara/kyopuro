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

VV ed;
V jd;
V cost;

void dfs(int p, int c)
{

  jd[p] = 1;
  cost[p] += c;

  REP(i, ed[p].size())
  {
    if (jd[ed[p][i]] == 0)
    {
      dfs(ed[p][i], cost[p]);
    }
  }

}

int main()
{
  int n, q;
  cin >> n >> q;
  jd.resize(n);
  ed.resize(n);
  cost.resize(n);
  REP(i, n - 1)
  {
    int a, b;
    cin >> a >> b;
    ed[a - 1].push_back(b - 1);
    ed[b - 1].push_back(a - 1);
  }
  REP(i, q)
  {
    int p, x;
    cin >> p >> x;

    cost[p - 1] += x;
  }

  dfs(0, 0);

  REP(i, n)
  {
    cout << cost[i] << " ";
  }
  cout << endl;

  return 0;
}