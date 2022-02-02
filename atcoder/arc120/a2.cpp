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

int main()
{
  int n;
  cin >> n;
  V a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  Vl maxsum(n);
  REP2(i, 1, n)
  {
    maxsum[i] = a[i - 1] + maxsum[i - 1];
  }

  Vl sum(n), suma(n);
  sum[0] = maxsum[0];
  suma[0] = a[0];

  REP2(i, 1, n)
  {
    sum[i] = sum[i - 1] + maxsum[i];
  }

  REP2(i, 1, n)
  {
    suma[i] = suma[i - 1] + a[i];
  }

  ll maxs = -1;
  REP(i, n)
  {
    maxs = maxs < a[i] ? a[i] : maxs;
    cout << sum[i] + maxs * (i + 1) + suma[i] << endl;
  }

  return 0;
}