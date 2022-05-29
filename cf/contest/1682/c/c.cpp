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

  REP(i, t)
  {
    int n;
    cin >> n;
    a[i].resize(n);
    REP(j, n)
    {
      cin >> a[i][j];
    }
  }

  V ssize(t);

  REP(i, t)
  {
    map<int, int> m;
    set<int> so;
    REP(j, a[i].size())
    {
      so.insert(a[i][j]);
    }
    int k = 0;
    for (int aa : so)
    {
      m[aa] = k;
      k++;
    }
    ssize[i] = so.size();
    REP(j, a[i].size())
    {
      a[i][j] = m[a[i][j]];
    }
  }

  REP(i, t)
  {
    V cnt(ssize[i]);
    REP(j, a[i].size())
    {
      cnt[a[i][j]]++;
    }

    int ans = 0;
    REP(j, ssize[i])
    {
      if (cnt[j] >= 2)
      {
        ans += 2;
      }
      else
      {
        ans++;
      }
    }

    if (cnt[ssize[i] - 1] == 1 && a[i].size() % 2 == 1)
    {
      ans += 2;
    }
    cout << ans / 2 << endl;
  }

  return 0;
}