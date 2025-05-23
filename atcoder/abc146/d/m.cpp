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

VV edge;
V used;
map<P, int> ans;
void dfs(int now, int pre)
{

  used[now] = 1;
  int num = 1;
  int c = now;
  int d = pre;
  if (c > d)
  {
    swap(c, d);
  }

  REP(i, edge[now].size())
  {

    if (used[edge[now][i]] == 0)
    {
      if (num == ans[{c, d}])
        num++;
      int a = now;
      int b = edge[now][i];
      if (a > b)
      {
        swap(a, b);
      }
      ans[{a, b}] = num;
      dfs(edge[now][i], now);
      num++;
    }
  }
}

int main()
{
  int n;
  cin >> n;

  used.resize(n);
  edge.resize(n);
  VP prob;

  REP(i, n - 1)
  {
    int a, b;
    cin >> a >> b;
    if (a > b)
    {
      swap(a, b);
    }
    prob.push_back({a - 1, b - 1});
    edge[a - 1].push_back(b - 1);
    edge[b - 1].push_back(a - 1);
  }

  int kk = -1;
  REP(i, n - 1)
  {
    int k = edge[i].size();
    kk = max(kk, k);
  }

  cout << kk << endl;

  dfs(0, -1);

  REP(i, n - 1)
  {
    cout << ans[prob[i]] << endl;
  }

  return 0;
}