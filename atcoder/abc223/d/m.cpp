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
V ans;
set<int> s;

void topo_sort()
{ // bfs
  int n = edge.size();
  vector<int> ind(n); // ind[i]: 頂点iに入る辺の数(次数)
  for (int i = 0; i < n; i++)
  { // 次数を数えておく
    for (auto e : edge[i])
    {
      ind[e]++;
    }
  }
  priority_queue<int , V, greater<int>> que;
  for (int a : s)
  { // 次数が0の点をキューに入れる
    if (ind[a] == 0)
    {
      que.push(a);
    }
  }
  while (!que.empty())
  { // 幅優先探索
    int now = que.top();
    ans.push_back(now);
    que.pop();
    for (auto e : edge[now])
    {
      ind[e]--;
      if (ind[e] == 0)
      {
        que.push(e);
      }
    }
  }
}

int main()
{

  int n, m;
  cin >> n >> m;
  edge.resize(n);

  REP(i, m)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    edge[a].push_back(b);
    s.insert(a);
    s.insert(b);
  }

  used.resize(n);

  topo_sort();

  if (ans.size() < s.size())
  {
    cout << -1 << endl;
    return 0;
  }

  int j = 0;
  REP(i, n)
  {
    if (s.count(i) == 1)
    {
      continue;
    }
    int t = j;
    for (j; j < ans.size(); j++)
    {
      if (i < ans[j])
      {
        for (t; t < j; t++)
        {
          cout << ans[t] + 1 << " ";
        }
        cout << i + 1 << " ";
        break;
      }
    }

    if (j == ans.size())
    {
      for (t; t < j; t++)
      {
        cout << ans[t] + 1 << " ";
      }
      REP2(l, i, n)
      {
        cout << l + 1 << " ";
      }
      break;
    }
  }

  for (j; j < ans.size(); j++)
  {
    cout << ans[j] + 1 << " ";
  }
  cout << endl;
  return 0;
}