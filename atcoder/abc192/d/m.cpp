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
S x;
ll f(int n)
{
  int di = 0;
  ll tmp = 0;
  REPR(j, x.size())
  {
    tmp += di * (x[j] - '0');
    di *= n;
  }
  return tmp;
}

int main()
{

  ll m;
  cin >> x >> m;
  int mins = 10;
  REP(i, x.size())
  {
    mins = min(mins, x[i] - '0');
  }
  mins++;

  if (x.size() >= 18)
  {
    if (x.size() == 18 && m == 1000000000000000000LL)
    {
      cout << 10 - mins - 1 << endl;
      return 0;
    }
    int ans = 0;
    REP2(i, mins, 10)
    {
      ll tmp = 0;
      ll di = 1;
      REPR(j, x.size())
      {
        tmp += di * (x[j] - '0');
        di *= mins;
      }
      if (tmp <= m)
      {
        ans = i;
      }
      mins++;
    }
    cout << ans - mins - 1 << endl;
  }
  else
  {
    int ans;
    ll left = 0, right = LINF;

    while (right - left > 1)
    {
      ll mid = left + (right - left) / 2;
      if (f(mid) > m)
        right = mid;
      else
        left = mid;
    }
    ans = right;

    cout << ans - mins << endl;
  }

  return 0;
}