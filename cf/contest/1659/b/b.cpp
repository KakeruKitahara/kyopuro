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
  vector<S> s(t);
  V k(t);
  REP(i, t)
  {
    int m;
    cin >> m >> k[i];
    cin >> s[i];
  }

  VV one(t);
  VV zero(t);

  REP(i, t)
  {
    REP(j, s[i].size())
    {
      if (s[i][j] == '1')
      {
        one[i].push_back(j);
      }
      else
      {
        zero[i].push_back(j);
      }
    }
  }

  REP(i, t)
  {
    V cnt(s[i].size());
    if (k[i] % 2 == 0)
    {
      if (zero[i].size() < k[i])
      {
        REP(j, zero[i].size())
        {
          cnt[zero[i][j]] = 1;
        }
        cnt[s[i].size() - 1] += k[i] - zero[i].size();
        if (zero[i].size() % 2 == 0)
        {
          REP(j, s[i].size())
          {
            s[i][j] = '1';
          }
        }
        else
        {
          REP(j, s[i].size() - 1)
          {
            s[i][j] = '1';
          }
          s[i][s[i].size() - 1] = '0';
        }
      }
      else
      {
        REP(j, k[i])
        {
          cnt[zero[i][j]] = 1;
          s[i][zero[i][j]] = '1';
        }
      }
    }
    else
    {
      if (one[i].size() < k[i])
      {
        REP(j, one[i].size())
        {
          cnt[one[i][j]] = 1;
        }
        cnt[s[i].size() - 1] += k[i] - one[i].size();
        if (one[i].size() % 2 == 1)
        {
          REP(j, s[i].size())
          {
            s[i][j] = '1';
          }
        }
        else
        {
          REP(j, s[i].size() - 1)
          {
            s[i][j] = '1';
          }
          s[i][s[i].size() - 1] = '0';
        }
      }
      else
      {
        REP(j, k[i])
        {
          cnt[one[i][j]] = 1;
          s[i][one[i][j]] = '0';
        }
        REP(j, s[i].size())
        {
          if (s[i][j] == '1')
            s[i][j] = '0';
          else
            s[i][j] = '1';
        }
      }
    }
    cout << s[i] << endl;
    REP(j, s[i].size())
    {
      cout << cnt[j] << " ";
    }
    cout << endl;
  }

  return 0;
}