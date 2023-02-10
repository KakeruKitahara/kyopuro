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

V used;
V mark;
vector<set<P>> edge;

void dfs(int p, int n)
{
  used[p] = 1;
  mark[p] = n;

  while (edge[p].size() != 0)
  {
    auto it = edge[p].begin();
    P k = *it;
    int x = n;
    if (k.first % 2 == 1)
    {
      x = (n + 1) % 2;
    }

    edge[k.second].erase(make_pair(k.first, p));
    edge[p].erase(it);
    dfs(k.second, x);
  }
}

int main()
{
  int n;
  cin >> n;
  edge.resize(n);
  used.resize(n);
  mark.resize(n);
  REP(i, n)
  {
    int u, v, w;
    cin >> u >> v >> w;
    edge[u - 1].insert(make_pair(w, v - 1));
    edge[v - 1].insert(make_pair(w, u - 1));
  }

  dfs(0, 0);

  REP(i, n)
  {
    cout << mark[i] << endl;
  }
  return 0;
}