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
  int h, w, n;
  cin >> h >> w >> n;
  V a(n), b(n), a2(n), b2(n);
  REP(i, n)
  {
    cin >> a[i] >> b[i];
    a2[i] = a[i];
    b2[i] = b[i];
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  REP(i, n)
  {
    auto p = lower_bound(a.begin(), a.end(), a2[i]);
    auto q = lower_bound(b.begin(), b.end(), b2[i]);
    cout << (p - a.begin()) + 1 << " ";
    cout << (q - b.begin()) + 1 << endl;
  }

  return 0;
}