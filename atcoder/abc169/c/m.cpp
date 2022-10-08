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

  // long double でも精度的にWAになる．
  ll a;
  cin >> a;
  S s;
  cin >> s;
  int b1, b2 = 0;
  int f = 0, d = 10;
  REP(i, s.size())
  {
    if (s[i] == '.')
    {
      f = 1;
      continue;
    }

    if (f == 0)
    {
      b1 = s[i] - '0';
    }
    else
    {
      b2 += (s[i] - '0') * d;
      d /= 10;
    }
  }
  ll b = b1 * 100 + b2;

  cout << a * b / 100 << endl;

  return 0;
}