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
constexpr int INF = 1000000000 + 8;
using mint = modint1000000007;

int main()
{
  int n;
  cin >> n;
  V t(n);
  vector<pair<double, double>> lr(n);
  REP(i, n)
  {
    cin >> t[i] >> lr[i].first >> lr[i].second;
    if (t[i] == 2)
      lr[i].second -= 0.5;
    else if (t[i] == 3)
      lr[i].first += 0.5;
    else if (t[i] == 4)
    {
      lr[i].second -= 0.5;
      lr[i].first += 0.5;
    }
  }

  ll ans = 0;
  REP(i, n)
  {
    REP2(j, i + 1, n)
    {
      if (!(lr[i].second < lr[j].first || lr[j].second < lr[i].first))
      {
        ans++;
      }
    }
  }
  cout << ans << endl;

  return 0;
}