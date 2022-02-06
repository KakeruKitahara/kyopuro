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
mint sum(mint a)
{
  if (a.val() % 2 == 0)
  {
    return a / 2 * (a + 1);
  }
  else
  {
    return (a + 1) / 2 * a;
  }
}

int main()
{
  ll n;
  cin >> n;
  ll n2 = n;

  int d = 0;
  while (n2 != 0)
  {
    d++;
    n2 /= 10;
  }

  mint ans = 0;
  mint k = 9;
  ll d2 = 1;
  REP(i, d)
  {
    if (i != d - 1)
    {
      ans += sum(k);
      k *= 10;
      d2 *= 10;
    }
    else
    {
      ans += sum(n - d2 + 1);
    }
  }

  cout << ans.val() << endl;

  return 0;
}