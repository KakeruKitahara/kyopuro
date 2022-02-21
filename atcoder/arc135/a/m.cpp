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
using mint = modint998244353;
map<ll, mint> mp;

void dfs(ll a)
{
  if (mp[a] != 0)
  {
    return;
  }
  if (5 > a)
  {
    mp[a] = a;
    return;
  }

  dfs(a / 2);
  dfs((a + 1) / 2);

  mp[a] = mp[a / 2];
  mp[a] *= mp[(a + 1) / 2];

  return;
}

int main()
{
  ll x;
  cin >> x;
  dfs(x);
  cout << mp[x].val() << endl;
  return 0;
}