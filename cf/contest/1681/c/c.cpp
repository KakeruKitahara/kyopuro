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
  VV a(t), b(t);
  VV a2(t), b2(t);
  REP(i, t)
  {
    int n;
    cin >> n;
    a[i].resize(n);
    b[i].resize(n);
    a2[i].resize(n);
    b2[i].resize(n);
    REP(j, n)
    {
      cin >> a[i][j];
    }
    REP(j, n)
    {
      cin >> b[i][j];
    }
  }

  REP(i, t)
  {
    set<int> aa, bb;
    REP(j, a[i].size())
    {
      aa.insert(a[i][j]);
      bb.insert(b[i][j]);
    }
    int cnt = 0;
    for (int k : aa)
    {
      REP(j, a[i].size())
      {
        if (k == a[i][j])
        {
          a2[i][j] = cnt;
        }
      }
      cnt++;
    }

    cnt = 0;
    for (int k : bb)
    {
      REP(j, a[i].size())
      {
        if (k == b[i][j])
        {
          b2[i][j] = cnt;
        }
      }
      cnt++;
    }
  }

  REP(i, t)
  {
    int ans;
    vector<P> ans2;

    int ff = 0;
    REP(k, a2[i].size())
    {
      int f = 0;
      int mina = IINF, minb = IINF;
      REP2(j, k, a2[i].size())
      {
        mina = min(a2[i][j], mina);
        minb = min(b2[i][j], minb);
      }
      REP2(j, k, a2[i].size())
      {
        if (a2[i][j] == mina && b2[i][j] == minb)
        {
          if (k == j)
          {
            f = 1;
            break;
          }
          ans2.push_back(make_pair(k + 1, j + 1));
          swap(a2[i][k], a2[i][j]);
          swap(b2[i][k], b2[i][j]);
          f = 1;
          break;
        }
      }
      if (f == 0)
      {
        break;
      }
    }

    REP(j, a2[i].size() - 1)
    {
      if (a2[i][j] > a2[i][j + 1])
      {
        ff = 1;
        break;
      }
    }
    REP(j, b2[i].size() - 1)
    {
      if (b2[i][j] > b2[i][j + 1])
      {
        ff = 1;
        break;
      }
    }
    if (ff == 0)
    {
      cout << ans2.size() << endl;
      REP(k, ans2.size())
      {
        cout << ans2[k].first << " " << ans2[k].second << endl;
      }
    }
    else
    {
      cout << -1 << endl;
    }
  }
  return 0;
}