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
  S s;
  cin >> s;

  V a(s.size());
  REP(i, a.size())
  {
    a[i] = s[i] - '0';
  }

  V e4;

  REP2(i, 1, 25)
  {
    e4.push_back(4 * i);
  }

  REP(i, e4.size())
  {
    V a2 = a;
    int f = 0;
    int b[2] = {e4[i] / 10, e4[i] % 10};
    V cnt(2);
    set<int> ind;
    REP(j, a.size())
    {
      if (b[0] == a2[j])
      {
        ind.insert(j);
        cnt[0]++;
      }
      else if (b[1] == a2[j])
      {
        ind.insert(j);
        a2[j] = -1;
        cnt[1]++;
      }

      if (ind.size() == 2)
      {
        break;
      }
    }

    if (b[0] == b[1])
    {
      if (cnt[0] >= 2)
      {
        f = 1;
      }
    }
    else
    {
      if (cnt[0] >= 1 && cnt[1] >= 1)
      {
        f = 1;
      }
    }

    if (f == 1)
    {

      if ((i + 1) % 2 == 1)
      {
        REP(j, a.size())
        {
          int ff = 0;
          for (int cc : ind)
          {
            if (cc == j)
            {
              ff = 1;
            }
          }
          if (a2[j] % 2 == 1 && ff == 0)
          {
            cout << "Yes" << endl;
            return 0;
          }
        }
      }
      else
      {
        if (a.size() == 2)
        {
          cout << "Yes" << endl;
          return 0;
        }
        REP(j, a.size())
        {
          int ff = 0;
          for (int cc : ind)
          {
            if (cc == j)
            {
              ff = 1;
            }
          }
          if (a2[j] % 2 == 0 && ff == 0)
          {
            cout << "Yes" << endl;
            return 0;
          }
        }
      }
    }
  }
  if (s == "8")
  {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;

  return 0;
}