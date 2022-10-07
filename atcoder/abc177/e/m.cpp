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
  V a(n);
  REP(i, n)
  {
    cin >> a[i];
  }

  V b;
  b = a;

  int f = 0;

  set<int> alls;
  REP(i, n)
  {
    set<int> aa;
    for (long long p = 2; p * p <= a[i]; ++p)
    {
      if (a[i] % p != 0)
      {
        continue;
      }

      while (a[i] % p == 0)
      {

        a[i] /= p;
      }

      if (aa.count(p) == 0)
      {
        if (alls.count(p) == 1)
        {
          f = 1;
        }
        alls.insert(p);
      }
      aa.insert(p);
    }
    if (a[i] != 1)
    {
      if (aa.count(a[i]) == 0)
      {
        alls.insert(a[i]);
      }
      aa.insert(a[i]);
    }
  }

  a = b;

  int ggg = __gcd(a[0], a[1]);

  if (f == 0)
  {
    cout << "pairwise coprime" << endl;
  }
  else
  {

    REP2(i, 2, n)
    {
      ggg = __gcd(a[i], ggg);
    }

    if (ggg == 1)
    {
      cout << "setwise coprime" << endl;
    }
    else
    {
      cout << "not coprime" << endl;
    }
  }

  return 0;
}