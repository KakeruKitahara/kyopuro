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
  int n, q;
  cin >> n >> q;
  V c(q), x(q), y(q);
  VV e(n + 1, V(2));
  REP(i, q)
  {
    cin >> c[i];
    if (c[i] == 3)
      cin >> x[i];
    else
      cin >> x[i] >> y[i];
    if (c[i] == 1)
    {
      e[x[i]][1] = y[i];
      e[y[i]][0] = x[i];
    }
    else if (c[i] == 2)
    {
      e[x[i]][1] = 0;
      e[y[i]][0] = 0;
    }
    else if (c[i] == 3)
    {
      int k = x[i];
      while (e[k][0] != 0)
      {
        k = e[k][0];
      }

      V ans;

      while (e[k][1] != 0)
      {
        ans.push_back(k);
        k = e[k][1];
      }
      ans.push_back(k);

      cout << ans.size() << " ";
      REP(j, ans.size())
      {
        cout << ans[j] << " ";
      }
      cout << endl;
    }
  }

  return 0;
}