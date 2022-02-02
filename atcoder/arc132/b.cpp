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
  V p(n);
  REP(i, n)
  {
    cin >> p[i];
  }

  int ans = INF;
  V samp, sampr;
  REP(i, n)
  {
    samp.push_back(i + 1);
    sampr.push_back(i + 1);
  }
  reverse(sampr.begin(), sampr.end());
  REP(cur, n)
  {
    if (p[cur] == 1)
    {
      int flg = 0;
      REP(j, n)
      {
        if (p[(cur + j) % n] == samp[j])
        {
          flg++;
        }
      }
      if (flg == n)
      {
        ans = min(ans, cur);
        break;
      }
    }
  }

  REP(cur, n)
  {
    if (p[cur] == n)
    {
      int flg = 0;
      REP(j, n)
      {
        if (p[(cur + j) % n] == sampr[j])
        {
          flg++;
        }
      }
      if (flg == n)
      {
        ans = min(ans, cur + 1);
        break;
      }
    }
  }

  REP(i, n)
  {
    int cur = 0 < i ? n - i : i;
    if (p[cur] == 1)
    {
      int flg = 0;
      REP(j, n)
      {
        if (p[(cur + j) % n] == samp[j])
        {
          flg++;
        }
      }
      if (flg == n)
      {
        ans = min(ans, i + 2);
        break;
      }
    }
  }

  REP(i, n)
  {
    int cur = 0 < i ? n - i : i;
    if (p[cur] == n)
    {
      int flg = 0;
      REP(j, n)
      {
        if (p[(cur + j) % n] == sampr[j])
        {
          flg++;
        }
      }
      if (flg == n)
      {
        ans = min(ans, i + 1);
        break;
      }
    }
  }

  cout << ans << endl;
  return 0;
}