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

int main()
{
  int n;
  cin >> n;

  mint u = 1;
  REP(i, n)
  {
    u *= 10;
  }

  vector<vector<int>> cb(n + 1, vector<int>(3, 0));
  for (int j = 0; j < n + 1; j++)
    cb[j][0] = 1;
  for (int i = 1; i < n + 1; i++)
  {
    for (int j = 1; j < 3; j++)
    {
      cb[i][j] = cb[i - 1][j - 1] + cb[i - 1][j];
    }
  }

  mint m = 0;
  mint m8 = 1;

  REP(i, n + 1)
  {
    m += cb[i][2] * m8 * 2;
    m8 *= 8;
  }

  mint ans = u - m;

  if (n == 1)
    cout
        << 0 << endl;
  else
    cout << ans.val() << endl;

  return 0;
}