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
VV edge;
V leader;
V flag;
int l;
void dfs(int p, int c)
{
  leader[p] = l;
  used[p] = c;

  REP(i, edge[p].size())
  {
    if (used[edge[p][i]] == used[p])
    {
      cout << 0 << endl;
      exit(0);
    }
    if (used[edge[p][i]] == -1)
    {
      dfs(edge[p][i], (c + 1) % 2);
    }
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  used.resize(n);
  fill(used.begin(), used.end(), -1);
  edge.resize(n);
  leader.resize(n);
  flag.resize(n);
  REP(i, m)
  {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }

  REP(i, n)
  {
    if (used[i] == -1)
    {
      l = i;
      dfs(i, 0);
    }
  }

  VV vcnt(n, V(2));
  VVl sum(n, Vl(2, 0));
  V vec(n);
  REP(i, n)
  {
    REP(j, edge[i].size())
    {
      vcnt[i][used[edge[i][j]]]++;
    }
    if (flag[i] == -1)
    {
      sum[leader[i]][0] = -LINF;
    }
    else
    {
      sum[leader[i]][used[i]]++;
    }
    vec[leader[i]]++;
  }

  ll sums = n;

  REP(i, n)
  {
    if (flag[i] == -1)
    {
      sums -= vec[leader[i]];
      vec[leader[i]] = 0;
    }
  }

  Vl ans1(n);
  REP(i, n)
  {
    if (sum[leader[i]][0] < 0)
    {
      ans1[leader[i]] = -LINF;
      ans1[i] = -LINF;
    }
    else
    {
      ans1[leader[i]] += sum[leader[i]][(used[i] + 1) % 2] - vcnt[i][(used[i] + 1) % 2];
    }
  }

  ll ans = 0;
  ll ansa = 0;
  int f = 0;
  REP(i, n)
  {
    if (ans1[i] > 0)
    {
      ans += (ans1[i] / 2);
    }

    if (ans1[i] >= 0)
    {

      ansa += sums - vec[leader[i]];
    }
  }

  cout << ans + ansa / 2  << endl;

  return 0;
}