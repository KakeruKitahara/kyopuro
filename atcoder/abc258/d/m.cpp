#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using V = vector<int>;
using Vl = vector<long long>;
using VV = vector<vector<int>>;
using VVl = vector<vector<long long>>;
using P = pair<int, int>;
using Pl = pair<long long, long long>;
using S = string;
using ll = long long;
constexpr int IINF = 1000000000 + 8;
constexpr long long LINF = 1000000000000000000LL + 8;
using mint = modint1000000007;
ll x;
ll n;
Vl a, b;
ll dfs(ll num, ll c)
{
  if (c == n - 1 || c == x - 1)
  {
    return (x - c - 1) * b[c] + num;
  }

  ll ans = min((x - c - 1) * b[c] + num, dfs(num + a[c + 1] + b[c + 1], c + 1));
  return ans;
}

int main()
{

  cin >> n >> x;
  a.resize(n);
  b.resize(n);
  REP(i, n)
  {
    cin >> a[i] >> b[i];
  }

  cout << dfs(a[0] + b[0], 0) << endl;

  return 0;
}