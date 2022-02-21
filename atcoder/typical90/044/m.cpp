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
  int n, q;
  cin >> n >> q;
  V a(n);
  V t(q), x(q), y(q);

  REP(i, n)
  {
    cin >> a[i];
  }
  REP(i, q)
  {
    cin >> t[i] >> x[i] >> y[i];
  }
  int s = 0;
  REP(i, q)
  {
    if (t[i] == 1)
      swap(a[(x[i] + s - 1) % n], a[(y[i] + s - 1) % n]);
    else if (t[i] == 2)
    {
      s--;
      if (s == -1)
        s = n - 1;
    }
    else
      cout << a[(x[i] - 1 + s) % n] << endl;
  }
  return 0;
}