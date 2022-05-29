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

  int n;
  cin >> n;
  S s;
  cin >> s;

  V sma;
  REP(i, n - 2)
  {
    int l = i, r = i + 2;
    if (s[i] == 'A' && s[i + 1] == 'R' && s[i + 2] == 'C')
    {
      while (s[l] == 'A' && 0 <= l)
      {
        l--;
      }
      while (s[r] == 'C' && r <= n - 1)
      {
        r++;
      }
      sma.push_back(min(r - i + 1, i - l - 1) + 1);
    }
  }

  sort(sma.begin(), sma.end());

  int ans = 0;
  int j = 0;
  int i = lower_bound(sma.begin(), sma.end(), 2) - sma.begin();
  int ccc = 0;
  if (sma.size() != 0)
  {
    while (1)
    {
      ccc++;
      if (ccc % 2 == 1)
      {
        if (i == sma.size())
        {
          ans += sma.size() - j;
          break;
        }
        while (sma[i] == 1)
        {
          i++;
        }
        if (i == sma.size())
        {
          ans += sma.size() - j;
          break;
        }

        ans++;
        sma[i]--;
        
        if (sma[i] == 1)
        {
          i++;
        }
        if (i == sma.size())
        {
          ans += sma.size() - j;
          break;
        }
      }
      else
      {
        ans++;
        if (i == j)
        {
          break;
        }
        j++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}