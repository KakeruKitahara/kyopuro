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

int n;

int dfs(ll ptr, int y)
{
  ll t = ptr;
  int cnt = 0;
  V dig;

  while (t != 0)
  {
    dig.push_back(t % 10);
    t /= 10;
    cnt++;
  }
  if (cnt == n)
  {
    return y;
  }

  int ans = IINF;

  REP(i, dig.size())
  {
    if (dig[i] != 1 && dig[i] != 0)
    {
      ans = min(dfs(ptr * dig[i], y + 1), ans);
    }
  }

  return ans;
}

int main()
{
  ll x;
  cin >> n >> x;

  int a = dfs(x, 0);
  if (a == IINF)
  {
    cout << -1 << endl;
  }
  else
  {
    cout << a << endl;
  }
  

  return 0;
}