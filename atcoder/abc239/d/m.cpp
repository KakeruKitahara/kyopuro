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
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  V s = {2,
         3,
         5,
         7,
         11,
         13,
         17,
         19,
         23,
         29,
         31,
         37,
         41,
         43,
         47,
         53,
         59,
         61,
         67,
         71,
         73,
         79,
         83,
         89,
         97,
         101,
         103,
         107,
         109,
         113,
         127,
         131,
         137,
         139,
         149,
         151,
         157,
         163,
         167,
         173,
         179,
         181,
         191,
         193,
         197,
         199};

  int f = 0;
  REP2(i, a, b + 1)
  {
    int m = 0;
    REP2(j, c, d + 1)
    {
      int l = 0;
      REP(k, s.size())
      {
        if (i + j == s[k])
        {
          l = 1;
        }
      }
      if (l == 1)
      {
        m++;
      }
    }
    if (m == 0)
    {
      cout << "Takahashi" << endl;
      return 0;
    }
  }
    cout << "Aoki" << endl;
  return 0;
}