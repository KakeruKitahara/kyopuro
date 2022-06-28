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
  ll k;
  cin >> n >> k;
  V a(n);
  REP(i, n)
  {
    cin >> a[i];
  }
  ll x = 0;
  ll xn = 0;

  V jd(n);
  V root;
  Vl rosum;
  Vl losum;
  root.push_back(xn);
  rosum.push_back(x);

  REP2(i, 1, k + 1)
  {
    x += a[xn];
    xn = x % n;
    root.push_back(xn);
    rosum.push_back(x);
    if (jd[xn] == 1)
    {
      int f = 0;
      ll sum;
      REP(j, root.size())
      {
        if (f == 1)
        {
          losum.push_back(rosum[j] - sum);
        }
        if (f == 0 && root[j] == xn)
        {
          f = 1;
          if (j == 0)
            sum = 0;
          else
            sum = rosum[j];
        }
      }

      x +=  (k - i) / losum.size() * losum.back();
      if ((k - i) % losum.size() != 0)
      {
        x += losum[(k - i) % losum.size() - 1];
      }

      break;
    }

    jd[xn] = 1;
  }

  cout << x << endl;

  return 0;
}