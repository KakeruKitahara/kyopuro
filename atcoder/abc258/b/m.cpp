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
  VV a(n, V(n));
  REP(i, n)
  {
    a[i].resize(n);
    S s;
    cin >> s;
    REP(j, n)
    {
      a[i][j] = s[j] - '0';
    }
  }

  VV b;

  REP(i, n)
  {
    V tmp;
    REP(l, 3)
    {
      REP(j, n)
      {
        tmp.push_back(a[i][j]);
      }
    }
    b.push_back(tmp);
  }
  REP(l, 3)
  {
    REP(i, n)
    {
      b.push_back(b[i]);
    }
  }
  ll ans = -1;
  REP2(i, n, 2 * n)
  {
    REP2(j, n, 2 * n)
    {

      V w = {-1, 0, 1};
      REP(k1, 3)
      {
        REP(k2, 3)
        {
          ll t = 0;

          if (k1 == 1 && 1 == k2)
            continue;
          int x = 0, y = 0;
          REP(f, n)
          {

            t += b[i + x][j + y];
            t *= 10;
            x += w[k1];
            y += w[k2];
          }

          ans = max(t, ans);
        }
      }
    }
  }

  cout << ans / 10 << endl;

  return 0;
}