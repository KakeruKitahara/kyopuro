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
using mint = modint998244353;

int main()
{
  int h, w;
  cin >> h >> w;
  vector<S> s(h);
  REP(i, h)
  {
    cin >> s[i];
  }

  mint ans = 1;
  if (s[0][0] == '.')
  {
    ans *= 2;
  }
  if (s[h - 1][w - 1] == '.')
  {
    ans *= 2;
  }

  if (h < w)
  {
    REP2(k, 1, w)
    {
      int i = 0, j = k;
      set<char> c;
      while (i <= min(k, h - 1))
      {
        c.insert(s[i][j]);
        j--;
        i++;
      }
      if (c.count('R') == 1 && c.count('B') == 1)
      {
        cout << 0 << endl;
        return 0;
      }
      if (c.count('.') == 1 && c.size() == 1)
      {
        ans *= 2;
      }
    }
    REP2(k, 1, h - 1)
    {
      int i = k, j = w - 1;
      set<char> c;
      while (i <= h - 1)
      {
        c.insert(s[i][j]);
        j--;
        i++;
      }
      if (c.count('R') == 1 && c.count('B') == 1)
      {
        cout << 0 << endl;
        return 0;
      }
      if (c.count('.') == 1 && c.size() == 1)
      {
        ans *= 2;
      }
    }
  }
  else
  {
    REP2(k, 1, h)
    {
      int i = k, j = 0;
      set<char> c;
      while (j <= min(k, w - 1))
      {
        c.insert(s[i][j]);
        j++;
        i--;
      }
      if (c.count('R') == 1 && c.count('B') == 1)
      {
        cout << 0 << endl;
        return 0;
      }
      if (c.count('.') == 1 && c.size() == 1)
      {
        ans *= 2;
      }
    }
      REP2(k, 1, w - 1)
    {
      int i = h - 1, j = k;
      set<char> c;
      while (j <= w - 1)
      {
        c.insert(s[i][j]);
        j++;
        i--;
      }
      if (c.count('R') == 1 && c.count('B') == 1)
      {
        cout << 0 << endl;
        return 0;
      }
      if (c.count('.') == 1 && c.size() == 1)
      {
        ans *= 2;
      }
    }
  }

  cout << ans.val() << endl;

  return 0;
}