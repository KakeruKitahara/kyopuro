#include <bits/stdc++.h>
using namespace std;
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

int main()
{
  int n, k;
  cin >> n >> k;
  V c(n);
  REP(i, n)
  {
    cin >> c[i];
  }

  map<int, int> cnt;
  int ans = -1;

  REP(i, k)
  {
    if (cnt.count(c[i]))
    {
      cnt[c[i]]++;
    }
    else
    {
      cnt[c[i]] = 1;
    }
  }

  int tmp = cnt.size();
  if (ans < tmp)
  {
    ans = tmp;
  }
  REP2(i, k, n)
  {
    // この場合分けは不要．defaultで0に初期化されている．
    if (cnt.count(c[i]))
    {
      cnt[c[i]]++;
    }
    else
    {
      cnt[c[i]] = 1;
    }
    if ((--cnt[c[i - k]]) == 0)
    {
      cnt.erase(c[i - k]);
    }
    int tmp = cnt.size();
    if (ans < tmp)
    {
      ans = tmp;
    }
  }
  cout << ans << endl;

  return 0;
}