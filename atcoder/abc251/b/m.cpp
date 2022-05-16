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
  int n, w;
  cin >> n >> w;
  V a(n);
  REP(i, n)
  {
    cin >> a[i];
  }

  set<int> ans;
  REP(i, n)
  {
    REP2(j, i + 1, n)
    {
      REP2(k, j + 1, n)
      {
        if (a[i] + a[j] + a[k] <= w)
        {
          ans.insert(a[i] + a[j] + a[k]);
        }
      }
    }
  }

  REP(i, n)
  {
    REP2(j, i + 1, n)
    {
      if (a[i] + a[j] <= w)
      {
        ans.insert(a[i] + a[j]);
      }
    }
  }

  REP(i, n)
  {
    if (a[i] <= w)
    {
      ans.insert(a[i]);
    }
  }

    cout << ans.size() << endl;

    return 0;
  }