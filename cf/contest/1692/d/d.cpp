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
  int t;
  cin >> t;
  V x(t);
  V h(t), m(t);

  REP(i, t)
  {
    S s;
    cin >> s;
    S h1;
    S h2;
    REP(j, 5)
    {

      if (j == 0 || j == 1)
      {
        h1 += s[j];
      }
      if (j == 3 || j == 4)
      {
        h2 += s[j];
      }
    }
    h[i] = stoi(h1);
    m[i] = stoi(h2);

    cin >> x[i];
  }

  REP(i, t)
  {
    int ans = 0;
    int sh = h[i], sm = m[i];
    while (1)
    {
      m[i] += x[i];
      if (m[i] >= 60)
      {
        h[i] += m[i] / 60;
        m[i] %= 60;
      }
      if (h[i] >= 24)
      {
        h[i] %= 24;
      }
      if (h[i] == m[i] / 10 + m[i] % 10 * 10)
      {
        ans++;
      }
      if (sh == h[i] && sm == m[i])
      {
        break;
      }
    }
    cout << ans << endl;
  }

  return 0;
}