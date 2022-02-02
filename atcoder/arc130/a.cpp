#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using V = vector<int>;
using VV = vector<vector<int>>;
using P = pair<int, int>;
using S = string;
using ll = long long;
constexpr int INF = 1000000000 + 8;
using mint = modint1000000007;

ll def(int n)
{
  ll ans = 0;
  REP2(i, 1, n + 1)
  {
    ans += i;
  }
  return ans;
}

int main()
{
  int n;
  S s;
  cin >> n >> s;
  V a;

  int tmp = 0;

  REP(i, n - 1)
  {
    if (s[i] == s[i + 1])
    {
      tmp++;
    }
    else
    {
      a.push_back(tmp);
      tmp = 0;
    }
  }
  a.push_back(tmp);

  ll ans = 0;
  REP(i, a.size())
  {
    ans += def(a[i]);
  }
  cout << ans << endl;
  return 0;
}