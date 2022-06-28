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

int main()
{
  int n;
  cin >> n;
  vector<mint> u(n * n + 1);
  u[1] = 1;
  REP2(i, 2, n * n + 1)
  {
    u[i] = u[i - 1] * i;
  }

  mint no = 0;
  REP2(i, n, n * n - n + 2)
  {
    no += u[n * n - (2 * n - 1)] * (i - 1) * (n * n - i) * u[n - 1] * u[n - 1];
  }

  no *= n * n;

  mint ans = u[n * n] - no;
  cout << ans.val() << endl;

  return 0;
}