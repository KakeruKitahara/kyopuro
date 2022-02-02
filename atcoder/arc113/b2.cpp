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
V d1 = {3, 9, 7, 1};
V d2 = {2, 4, 8, 6};
V d3 = {7, 9, 3, 1};
V d4 = {8, 4, 2, 6};

int f(ll a, ll b)
{
  if (a == 0 || a == 1 || a == 5 || a == 6)
    return a;
  else if (a == 2)
    return d2[0 <= (b - 1) % 4 ? (b - 1) % 4 : (b - 1) % 4 + 4];
  else if (a == 3)
    return d1[0 <= (b - 1) % 4 ? (b - 1) % 4 : (b - 1) % 4 + 4];
  else if (a == 7)
    return d3[0 <= (b - 1) % 4 ? (b - 1) % 4 : (b - 1) % 4 + 4];
  else if (a == 8)
    return d4[0 <= (b - 1) % 4 ? (b - 1) % 4 : (b - 1) % 4 + 4];
  else if (a == 4)
    return d2[0 <= (b * 2 - 1) % 4 ? (b * 2 - 1) % 4 : (b * 2 - 1) % 4 + 4];
  else
    return d1[0 <= (b * 2 - 1) % 4 ? (b * 2 - 1) % 4 : (b * 2 - 1) % 4 + 4];
}

int pow(ll x, ll n)
{
  long long ret = 1;
  while (n > 0)
  {
    if (n & 1)
      ret = ret * x % 4; // n の最下位bitが 1 ならば x^(2^i) をかける
    x = x * x % 4;
    n >>= 1; // n を1bit 左にずらす
  }
  return ret % 4;
}

int main()
{
  ll a, b, c;
  cin >> a >> b >> c;
  int d = pow(b, c);
  int k = f(a % 10, d);

  cout << k << endl;
  return 0;
}
