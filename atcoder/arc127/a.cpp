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

ll pows(int a, int n)
{
  ll ans = 1;
  REP2(i, 1, n + 1)
  {
    ans *= a;
  }

  return ans;
}

int main()
{

  ll n;
  cin >> n;
  ll tmp = n;

  int digit = 0;
  while (tmp > 0)
  {
    tmp /= 10;
    digit++;
  }
  ll ans = 0;

  digit--;
  while (digit >= 0)
  {
    if (n >= 2 * pows(10, digit))
    {
      ans += pows(10, digit - 1) * (digit + 1);
    }
    else
    {
      ans += n % pows(10, digit) * (digit + 1);
    }
    digit--;
    n /= 10;
  }

  cout << ans << endl;

  return 0;
}