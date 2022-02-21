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
  vector<S> s(n), t(n);
  int f = 0;
  int u, b, l = 1000, r = -1;
  int u2, b2, l2 = 1000, r2 = -1;
  REP(i, n)
  {
    REP(j, n)
    {
      char tmp;
      cin >> tmp;
      s[i].push_back(tmp);
      if (tmp == '#')
      {
        if (f == 0)
        {
          u = i;
          f = 1;
        }
        r = max(r, j);
        l = min(l, j);
        b = i;
      }
    }
  }
  f = 0;
  REP(i, n)
  {
    REP(j, n)
    {
      char tmp;
      cin >> tmp;
      t[i].push_back(tmp);
      if (tmp == '#')
      {
        if (f == 0)
        {
          u2 = i;
          f = 1;
        }
        r2 = max(r2, j);
        l2 = min(l2, j);
        b2 = i;
      }
    }
  }

  vector<S> s2, t2;

  REP2(i, u, b + 1)
  {
    S tmp;
    REP2(j, l, r + 1)
    {
      tmp.push_back(s[i][j]);
    }
    s2.push_back(tmp);
  }

  REP2(i, u2, b2 + 1)
  {
    S tmp;
    REP2(j, l2, r2 + 1)
    {
      tmp.push_back(t[i][j]);
    }
    t2.push_back(tmp);
  }

  f = 0;
  if (s2.size() == t2.size() && s2[0].size() == t2[0].size())
  {
    f = 1;
  }
  if (s2.size() == t2[0].size() && s2[0].size() == t2.size())
  {
    f = 1;
  }

  if (f == 0)
  {
    cout << "No" << endl;
    return 0;
  }

  int ans = 0;
  REP(i, min(s2.size(), t2.size()))
  {
    REP(j, min(s2[0].size(), t2[0].size()))
    {
      if (s2[i][j] == t2[i][j])
      {
        ans++;
      }
    }
  }
  if (ans == s2.size() * s2[0].size())
  {
    cout << "Yes" << endl;
    return 0;
  }

  ans = 0;
  REP(i, min(s2.size(), t2[0].size()))
  {
    REP(j, min(s2[0].size(), t2.size()))
    {
      if (s2[i][j] == t2[t2.size() - 1 - j][i])
      {
        ans++;
      }
    }
  }
  if (ans == s2.size() * s2[0].size())
  {
    cout << "Yes" << endl;
    return 0;
  }

  ans = 0;
  REP(i, min(s2.size(), t2.size()))
  {
    REP(j, min(s2[0].size(), t2[0].size()))
    {
      if (s2[i][j] == t2[t2.size() - 1 - i][t2[0].size() - 1 - j])
      {
        ans++;
      }
    }
  }
  if (ans == s2.size() * s2[0].size())
  {
    cout << "Yes" << endl;
    return 0;
  }

  ans = 0;
  REP(i, min(s2.size(), t2[0].size()))
  {
    REP(j, min(s2[0].size(), t2.size()))
    {
      if (s2[i][j] == t2[j][t2[0].size() - 1 - i])
      {
        ans++;
      }
    }
  }
  if (ans == s2.size() * s2[0].size())
  {
    cout << "Yes" << endl;
    return 0;
  }

  cout << "No" << endl;
  return 0;
}