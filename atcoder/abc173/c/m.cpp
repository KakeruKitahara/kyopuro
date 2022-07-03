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
  int h, w, k;
  cin >> h >> w >> k;
  vector<S> c(h);
  REP(i, h)
  {
    cin >> c[i];
  }

  int ans = 0;

  for (int bit = 0; bit < (1 << h + w); bit++) // 1 << n = 2^n通り.
  {
    V hv, wv;
    for (int i = 0; i < h + w; i++)
    { // bit桁までi桁を調べる.
      if (bit & (1 << i))
      {
        if (i < h)
        {
          hv.push_back(i);
        }
        else
        {
          wv.push_back(i - h);
        }
      }
    }

    int cnt = 0;

    REP(hj, h)
    {
      int f = 0;
      REP(hvi, hv.size())
      {
        if (hv[hvi] == hj)
        {
          f = 1;
        }
      }

      if (f == 0)
      {
        REP(wj, w)
        {
          int g = 0;
          REP(wvi, wv.size())
          {
            if (wv[wvi] == wj)
            {
              g = 1;
            }
          }

          if (g == 0)
          {
            if (c[hj][wj] == '#')
            {
              cnt++;
            }
          }
        }
      }
    }

    if (cnt == k)
    {
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}