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

  s.push_back('X');
  n++;

  V se;
  V sma;
  REP(i, n - 2)
  {
    if (s[i] == 'A' && s[i + 1] == 'R' && s[i + 2] == 'C')
    {
      se.push_back(i);
    }
  }

  se.push_back(IINF);

  sma.resize(se.size() - 1);

  int a = 0;
  int c = 0;
  int j = 0;
  int aa, cc;
  int f = 0;
  REP(i, n)
  {
    if (s[i] == 'A')
    {
      if (i == se[j])
      {
        aa = a;
      }
      a++;
      continue;
    }
    else
    {
      a = 0;
    }

    if (s[i] == 'C')
    {
      if (f == 1)
      {
        c++;
      }
      if (i == se[j] + 2)
      {
        f = 1;
      }
      continue;
    }
    else
    {
      if (f == 1)
      {
        cc = c;
        f = 0;
        sma[j] = min(aa, cc);
        j++;
      }
    }
  }

  sort(sma.rbegin(), sma.rend());

  int ans = 0;
  int i = 0;
  j = sma.size() - 1;
  int ccc = 0;
  if (sma.size() != 0)
  {
    while (1)
    {
      ccc++;
      if (ccc % 2 == 1)
      {
        ans++;
        sma[i]--;
        if (sma[i] == -1)
        {
          if (i == j)
          {
            break;
          }
          i++;
        }
      }
      else
      {
        ans++;
        sma[j]--;
        if (sma[j] == -1)
        {
          if (i == j)
          {
            break;
          }
          j--;
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}