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
  ll n, l, r;

  cin >> n >> l >> r;

  ll t = n;
  V num;
  while (t > 0)
  {
    num.push_back(t % 2);
    t /= 2;
  }

  ll ans = 0;
  ll d = 1;
  ll a, b;
  REP(i, num.size())
  {
    a = max(l, num[i] * d);
    b = min(r, max(0ll, num[i] * d * 2 - 1));
    ans += max(0ll, b - a + 1); // a <= x <= bより，a <= bとしないといけない．

    d *= 2;
  }
  cout << ans << endl;

  return 0;
}

/* 誤答
int main()
{
  ll n, l, r;

  cin >> n >> l >> r;

  ll t = n;
  V num;
  while (t > 0)
  {
    num.push_back(t % 2);
    t /= 2;
  }


  ll ans = 0;
  ll d = 1;
  int f = 1;
  int f2 = 1;
  REP(i, num.size())
  {
    if (l <= d && d <= r) // このif文で様々な例外ケースを個別で処理しなければいけないため，minやmaxを用いる．(ex : l60~ etc)
    {
      f2 = 0;
      if (f == 1)
      {
        ans += max(0ll, num[i] * d - l);
        f = 0;
      }
      if (r < d * 2)
      {
        ans += max(0ll, num[i] * r - d + 1);
        break;
      }
      ans += num[i] * d;
    }
    d *= 2;
  }
  d = 1;
  if (f2 == 1)
  {
    REP(i, 64)
    {
      if (d <= l && r < d * 2)
      {
        ans += r - l + 1;
        break;
      }
      d *= 2;
    }
  }

  cout << ans << endl;

  return 0;
}
*/