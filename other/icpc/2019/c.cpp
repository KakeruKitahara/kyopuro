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
set<int> as;
V w;
V ans;

void dfs(int sum, int i, int f, int m)
{
  if (f == 1)
  {
    sum += w[i];
  }
  else if (f == 2)
  {
    sum -= w[i];
  }

  if (i == m - 1)
  {
    as.insert(sum);
    return;
  }

  REP(j, 3)
  {
    dfs(sum, i + 1, j, m);
  }
}

void solve(int m, int n)
{
  V a(n);
  w.resize(m);

  REP(i, n)
  {
    cin >> a[i];
  }
  REP(i, m)
  {
    cin >> w[i];
  }

  REP(i, 3)
  {
    dfs(0, 0, i, m);
  }

  vector<set<int>> sv(n);
  set<int> s1;

  REP(i, n)
  {
    for (int x : as)
    {
      sv[i].insert(abs(x - a[i]));
    }
  }

  sort(sv.begin(), sv.end());

  for (int x : sv[0])
  {
    s1.insert(x);
  }

  int f = 0;
  REP2(i, 1, n)
  {
    set<int> s2;
    if (*sv[i].begin() == 0 && *s1.begin() == 0)
    {
      for (int x : sv[i])
      {
        s1.insert(x);
      }
      s2 = s1;
    }
    else if (*sv[i].begin() == 0)
    {
      s2 = s1;
    }
      else if (*s1.begin() == 0 && f == 0)
    {
      s2 = sv[i];
      f = 1;
    }
    else
    {
      for (int x : sv[i])
      {
        if (s1.count(x) == 1)
        {
          s2.insert(x);
        }
      }
      f = 1;
    }
    s1 = s2;
  }

  if (s1.size() == 0)
  {
    ans.push_back(-1);
  }
  else
  {
    ans.push_back(*s1.begin());
  }
  w.clear();
  as.clear();
}

int main()
{
  while (1)
  {
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0)
    {
      break;
    }
    solve(m, n);
  }

  REP(i, ans.size())
  {
    cout << ans[i] << endl;
  }

  return 0;
}