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
  S c, s;
  cin >> c;
  int r = 0;

  REP(i, n)
  {
    if (c[i] == 'R')
    {
      r++;
    }
  }

  REP(i, r)
  {
    s.push_back('R');
  }
  REP(i, n - r)
  {
    s.push_back('W');
  }

  int ans1 = 0, ans2 = 0;
  REP(i, n)
  {
    if (c[i] == 'W' && s[i] == 'R')
    {
      ans1++;
    }
    if (c[i] == 'R' && s[i] == 'W')
    {
      ans2++;
    }
  }

  cout << max(ans1, ans2) << endl;
  return 0;
}