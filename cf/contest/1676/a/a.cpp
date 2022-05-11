#include <bits/stdc++.h>
using namespace std;
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

int main()
{
  int n;
  cin >> n;
  V a(n);
  REP(i, n)
  {
    cin >> a[i];
  }

  V ans(n);

  REP(i, n)
  {
    int s1 = 0, s2 = 0;
    REP(j, 3)
    {
      s1 += a[i] % 10;
      a[i] /= 10;
    }
    REP(j, 3)
    {
      s2 += a[i] % 10;
      a[i] /= 10;
    }
    if (s1 == s2)
    {
      ans[i] = 1;
    }
  }

  REP(i, n)
  {
    if (ans[i])
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }

  return 0;
}