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
  int a, b, c, d, e, f, x;
  cin >> a >> b >> c >> d >> e >> f >> x;

  int s = 1, s1 = 1;
  int k1 = 0, k2 = 0;
  int f1 = 0;
  while (s <= x)
  {
    if (f1 == 0)
    {
      k1 += b;
      if (s1 == a)
      {
        f1= 1;
        s1 = 0;
      }
    }
    else if (f1 == 1)
    {
      if (s1 == c)
      {
        f1 = 0;
        s1 = 0;
      }
    }
    s1++;
    s++;
  }
  s = 1, s1 = 1;
   f1 = 0;
  while (s <= x)
  {
    if (f1 == 0)
    {
      k2 += e;
      if (s1 == d)
      {
        f1 = 1;
        s1 = 0;
      }
    }
    else if (f1 == 1)
    {
      if (s1 == f)
      {
        f1 = 0;
        s1 = 0;
      }
    }
    s1++;
    s++;
  }

  if (k1 == k2)
  {
    cout << "Draw" << endl;
  }
  else if (k1 < k2)
  {
    cout << "Aoki" << endl;
  }
  else
  {
    cout << "Takahashi" << endl;
  }

  return 0;
}