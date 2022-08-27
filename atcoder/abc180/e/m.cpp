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

template <class T>
bool chmin(T &a, const T &b)
{
  if (b < a)
  {
    a = b;
    return 1;
  }
  return 0;
}

int main()
{

  int n;
  cin >> n;
  V x(n), y(n), z(n);
  REP(i, n)
  {
    cin >> x[i] >> y[i] >> z[i];
  }

  map<P, int> mp;

  REP(i, n)
  {
    REP(j, n)
    {
      mp[make_pair(i, j)] = abs(x[i] - x[j]) + abs(y[i] - y[j]) + max(0, z[j] - z[i]);
    }
  }

  VV dp(1 << n, V(n, IINF));
  dp[0][0] = 0;

  REP(s, 1 << n)
  {
    REP(v, n)
    {
      REP(u, n)
      {
        if (s != 0 && !(s & (1 << u)))
          continue; // u を含まない場合を除く
        if ((s & (1 << v)) == 0)
        {
          if (v != u)
            chmin(dp[s | (1 << v)][v], dp[s][u] + mp[make_pair(u, v)]);
        }
      }
    }
  }

  cout << dp[(1 << n) - 1][0] << endl;
  return 0;
}