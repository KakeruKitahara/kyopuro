#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using V = vector<int>;
using Vl = vector<long long>;
using VV = vector<vector<int>>;
using VVV = vector<vector<vector<int>>>;
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

  V n(t), e(t);
  vector<vector<vector<ll>>> a(t);
  vector<vector<vector<ll>>> b(t);
  vector<vector<vector<pair<ll, ll>>>> c(t);
  REP(i, t)
  {
    cin >> n[i] >> e[i];

    a[i].resize(e[i]);
    REP(j, n[i])
    {
      int aa;
      cin >> aa;
      a[i][j % e[i]].push_back(aa);
    }
  }

  REP(i, t)
  {
    b[i].resize(a[i].size());
    c[i].resize(a[i].size());
    REP(j, a[i].size())
    {
      b[i][j].resize(a[i][j].size());
      c[i][j].resize(a[i][j].size());
    }
  }

  REP(i, t)
  {
    ll ans = 0;
    REP(j, e[i])
    {
      REP(k, a[i][j].size())
      {
        int prime = 0;
        if (a[i][j][k] == 1)
        {
          prime = 2;
        }
        else
        {
          for (int l = 2; l * l <= a[i][j][k]; l++)
          {
            if (a[i][j][k] % l == 0)
            {
              prime = 1;
            }
          }
        }
        b[i][j][k] = prime;
      }
      int f = 0;
      int ind = -1;

      REP(k, a[i][j].size())
      {
        if (b[i][j][k] == 0)
        {
          if (f == 0)
          {
            f = 1;
            ind = k;
          }
          else
          {
            ans += k - ind - 1;
            c[i][j][ind].first = k - ind - 1;
            ind = k;
          }
        }
        else if (b[i][j][k] == 1 && f == 1)
        {
          f = 0;
          c[i][j][ind].first = k - ind - 1;
          ans += k - ind - 1;
        }
      }
      if (f == 1)
      {
        c[i][j][ind].first = a[i][j].size() - ind - 1;
        ans += a[i][j].size() - ind - 1;
      }
      reverse(c[i][j].begin(), c[i][j].end());
      reverse(b[i][j].begin(), b[i][j].end());
      f = 0;
      REP(k, a[i][j].size())
      {
        if (b[i][j][k] == 0)
        {
          if (f == 0)
          {
            f = 1;
            ind = k;
          }
          else
          {
            ans += k - ind - 1;
            c[i][j][ind].second = k - ind - 1;
            ind = k;
          }
        }
        else if (b[i][j][k] == 1 && f == 1)
        {
          f = 0;
          c[i][j][ind].second = k - ind - 1;
          ans += k - ind - 1;
        }
      }
      if (f == 1)
      {
        ans += a[i][j].size() - ind - 1;
        c[i][j][ind].second = a[i][j].size() - ind - 1;
      }
      REP(k, a[i][j].size())
      {
        ans += c[i][j][k].first * c[i][j][k].second;
      }
    }
    cout << ans << endl;
  }

  return 0;
}