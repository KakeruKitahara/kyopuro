#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using V = vector<int>;
using VV = vector<vector<int>>;
using P = pair<int, int>;
using S = string;
using ll = long long;
constexpr int INF = 1000000000 + 8;
using mint = modint1000000007;

int main()
{
  int q;
  cin >> q;
  V t(q);
  vector<ll> x(q);
  V a(1048576, -1);
  V b(1048576);

  REP(i, 1048576)
  {
    b[i] = i;
  }

  REP(i, q)
  {
    cin >> t[i] >> x[i];
  }

  REP(i, q)
  {
    if (t[i] == 1)
    {
      a[b[x[i] % 1048576]] = x[i];
      b.erase(b.begin() + x[i] % 1048576);
    }
    else
    {
      cout << a[x[i] % 1048576] << endl;
    }
  }

  return 0;
}