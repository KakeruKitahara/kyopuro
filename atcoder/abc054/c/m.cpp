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

/* Euclid  */
template <class X>
X gcd(X a, X b)
{
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

/* pow  */
template <class X>
X pow(X x, X n)
{
  X ret = 1;
  while (n > 0)
  {
    if (n & 1)
      ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}

/* fenick tree */

VV edge;
V used;
int n, m;

int dfs(int ptr, int num)
{
  ll cnt = 0;
  used[ptr] = 1;
  if (n == num)
  {
    cnt++;
  }

  REP(i, edge[ptr].size())
  {
    if (used[edge[ptr][i]] == 0)
    {
      cnt += dfs(edge[ptr][i], num + 1);
    }
  }

  used[ptr] = 0;

  return cnt;
}

int main()
{

  cin >> n >> m;
  edge.resize(n);
  set<P> k;
  REP(i, m)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (a != b)
    {
      k.insert(make_pair(a, b));
      k.insert(make_pair(b, a));
    }
  }

  for (P i : k)
  {
    edge[i.first].push_back(i.second);
  }
  ll ans = 0;
  used.resize(n);
  ans += dfs(0, 1);

  cout << ans << endl;

  return 0;
}