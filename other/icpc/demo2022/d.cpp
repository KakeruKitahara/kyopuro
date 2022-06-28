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

void solve(int n, int kp, int kq, int kr)

{
  kp--;
  kq--;
  kr--;
  int kkp = kp;
  Vl x(n), y(n);
  REP(i, n)
  {
    cin >> x[i] >> y[i];
  }

  ll ans = LINF;
  int l = 100000000 / n;
  do
  {
    int avx = x[kp] - x[kq];
    int ad = avx / l;
    int avy = y[kp] - y[kq];
    int bvx = x[kq] - x[kr];
    int bvy = y[kq] - y[kr];
    int cvx = x[kr] - x[kp];
    int cvy = y[kr] - y[kp];
    REP(i, l)
    {
      ll a = (x[kp] - x[kq]) * (x[kp] - x[kq]) + (y[kp] - y[kq]) * (y[kp] - y[kq]);
      ll b = (x[kq] - x[kr]) * (x[kq] - x[kr]) + (y[kq] - y[kr]) * (y[kq] - y[kr]);
      ll c = (x[kr] - x[kp]) * (x[kr] - x[kp]) + (y[kr] - y[kp]) * (y[kr] - y[kp]);

      ll s = 4 * b * c - (a - b - c) * (a - b - c);

      ans = min(s, ans);
    }
    kp++;
    kr++;
    kq++;

    if (kp == n)
    {
      kp = 0;
    }
    if (kq == n)
    {
      kq = 0;
    }
    if (kr == n)
    {
      kr = 0;
    }
  } while (kp != kkp);

  cout << fixed << setprecision(20) << 1 / 4.0 * sqrt(ans) << endl;
}

int main()
{
  while (1)
  {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == 0 && b == 0 && c == 0 && d == 0)
    {
      break;
    }
    solve(a, b, c, d);
  }

  return 0;
}