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
constexpr int INF = 1000000000 + 8;
using mint = modint1000000007;

mint sig(ll a)
{
  mint k = a;
  return k * (k + 1) / 2;
}

mint sigmasa(ll bg, ll sm)
{
  return sig(bg) - sig(sm - 1);
}

int main()
{
  ll l, r;
  cin >> l >> r;

  l--;
  ll tmp = 1;
  mint ans2 = 0, ans1 = 0;
  // ll型に毎回10をかけることで10^19になってオーバーフローしr>=tmpが崩壊してしまうので，そこの処理をする．
  while (r >= tmp && tmp != 1000000000000000000LL)
  {
    ans1 += sigmasa(r, tmp);
    tmp *= 10;
  }
  if (r == 1000000000000000000LL)
  {
    ans1 += sigmasa(r, tmp);
  }

  tmp = 1;
  while (l >= tmp && tmp != 1000000000000000000LL)
  {
    ans2 += sigmasa(l, tmp);
    tmp *= 10;
  }

  mint ans = ans1 - ans2;

  cout << ans.val() << endl;
  return 0;
}