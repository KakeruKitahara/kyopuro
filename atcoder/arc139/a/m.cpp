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

ll pow(ll a, ll b)
{
  ll c = 1;
  REP(i, b)
  {
    c *= a;
  }
  return c;
}

int main()
{
  int n;
  cin >> n;
  Vl t(n);

  REP(i, n)
  {
    cin >> t[i];
  }

  ll a = 0;

  REP(i, n)
  {
    ll left = 0, right = (LINF / pow(2, t[i]) + 1) / 2 + 100;

    while (right - left > 1)
    {
      ll mid = left + (right - left) / 2;
      if ((mid * 2 - 1) * pow(2, t[i]) > a)
        right = mid;
      else
        left = mid;
    }
    a = (right * 2 - 1) * pow(2, t[i]);
  }

  cout << a << endl;

  return 0;
}