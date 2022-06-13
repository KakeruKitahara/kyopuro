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
  V m, n, p;
  VV a, b;
  while (1)
  {
    int m2, n2, p2;
    cin >> m2 >> n2 >> p2;
    if (m2 == 0 && n2 == 0 && p2 == 0)
    {
      break;
    }
    p.push_back(p2);
    m.push_back(m2);
    n.push_back(n2);
    V a2(n2), b2(n2);
    REP(i, n2)
    {
      cin >> a2[i] >> b2[i];
    }
    a.push_back(a2);
    b.push_back(b2);
  }

  REP(i, n.size())
  {
    set<int> o;
    int f = 0;
    o.insert(p[i]);
    REP(j, n[i])
    {
      for (int k : o)
      {
        if (k == a[i][j] || k == b[i][j])
        {
          o.insert(a[i][j]);
          o.insert(b[i][j]);
          break;
        }
      }
    }
    cout << o.size() << endl;
  }

  return 0;
}