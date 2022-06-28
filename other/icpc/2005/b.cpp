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

void solve(int n)
{
  int m;
  cin >> m;

  vector<P> a0(m);
  REP(i, m)
  {
    cin >> a0[i].first >> a0[i].second;
  }
  vector<P> c(m);
  REP(j, m)
  {
    c[j].first = a0[j].first - a0[0].first;
    c[j].second = a0[j].second - a0[0].second;
  }

  vector<vector<P>> a(n);
  REP(i, n)
  {
    int m2;
    cin >> m2;
    a[i].resize(m2);
    REP(j, m2)
    {
      cin >> a[i][j].first >> a[i][j].second;
    }
  }

  REP(i, n)
  {
    REP(l, 2)
    {
      vector<P> b(a[i].size());
      if (a[i].size() != a0.size())
      {
        break;
      }
      REP(j, a[i].size())
      {

        if (l == 0)
        {
          b[j].first = a[i][j].first - a[i][0].first;
          b[j].second = a[i][j].second - a[i][0].second;
        }
        else
        {
          b[j].first = a[i][j].first - a[i][a[i].size() - 1].first;
          b[j].second = a[i][j].second - a[i][a[i].size() - 1].second;
        }
      }
      if (l == 1)
      {
        reverse(b.begin(), b.end());
      }
      REP(j, 4)
      {
        int cnt = 0;
        REP(k, a[i].size())
        {
          if (b[k].first == c[k].first && c[k].second == b[k].second)
          {
            cnt++;
          }
        }
        if (cnt == a[i].size())
        {
          cout << i + 1 << endl;
          break;
        }
        REP(k, a[i].size())
        {
          swap(b[k].first, b[k].second);
          b[k].first = -b[k].first;
        }
      }
    }
  }
  cout << "+++++" << endl;
}

int main()
{
  while (1)
  {
    int a;
    cin >> a;
    if (a == 0)
    {
      break;
    }
    solve(a);
  }

  return 0;
}