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
  ll a, b;

  cin >> a >> b;
  ll cnt = 1;
  if (__gcd(b, a) == 1)
  {
    cout << b - a << endl;
    return 0;
  }
  while (1)
  {
    ll ca = cnt, cb = 0;
    REP(i, cnt + 1)
    {

      ll xa = a + ca, xb = b - cb;
      if (__gcd(xb, xa) == 1)
      {
        cout << xb - xa << endl;
        return 0;
      }
      ca--;
      cb++;
    }
    cnt++;
  }
  return 0;
}