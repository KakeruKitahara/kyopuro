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

V bi(ll n)
{
  V r;
  while (n != 0)
  {
    r.push_back(n % 2 == 0 ? 0 : 1);
    n /= 2;
  }
  return r;
}

int main()
{
  int t;
  cin >> t;
  Vl a(t), s(t);
  REP(i, t)
  {
    cin >> a[i] >> s[i];
  }

  REP(i, t)
  {
    V a2 = bi(a[i]), s2 = bi(s[i]);
    int f = 0;
    V x, y;
    REP(j, a2.size())
    {
      if(a2[j] == 1){
        x.push_back(1);
      }
    }
  }

  return 0;
}