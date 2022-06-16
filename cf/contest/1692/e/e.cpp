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
  int t;
  cin >> t;
  VV a(t);
  V s(t);
  REP(i, t)
  {
    int n;
    cin >> n;
    cin >> s[i];
    a[i].resize(n);
    REP(j, n)
    {
      cin >> a[i][j];
    }
  }

  REP(i, t)
  {
    int x = s[i];
    int n = a[i].size();
    int right = 0; 
    long long sum = 0; 
    int maxs = IINF;
    for (int left = 0; left < n; ++left)
    {
      while (right < n && sum + a[i][right] <= x)
      {
        sum += a[i][right];
        ++right;
      }
      if (sum == s[i])
      {
        maxs = min(maxs, left + n - right);
      }


      if (right == left)
        ++right;
      else
        sum -= a[i][left];
    }

    if (maxs == IINF)
    {
      cout << -1 << endl;
    }
    else
    {
      cout << maxs << endl;
    }
  }

  return 0;
}