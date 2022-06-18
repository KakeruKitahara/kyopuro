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
  V n, m;
  VV a, b;
  while (1)
  {
    int n2, m2;
    cin >> n2 >> m2;
    n.push_back(n2);
    m.push_back(m2);
    V a2, b2;
    REP(j, n2)
    {
      int a3;
      cin >> a3;
      a2.push_back(a3);
    }
    REP(j, n2)
    {
      int b3;
      cin >> b3;
      b2.push_back(b3);
    }
    b.push_back(b2);
    a.push_back(a2);
  }

  REP(i, n.size())
  {
    int ptr = 0;
    while (1)
    {
    }
  }
  return 0;
}