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
int n;
int ans = 0;
VV e(n);

void f(int p, V jd)
{
  if (p == n - 1)
  {
    int f = 0;
    int f1 = 0;
    REP(i, n)
    {
      if (jd[i] == 2)
      {
        f++;
      }
      else if (jd[i] == 1)
      {
        f1++;
      }
    }
    if (jd[0] == 1 && f == n - 2 && f1 == 2)
    {
      ans++;
    }
    return;
  }

  f(p + 1, jd);

  jd[p]++;
  REP(i, e[p].size())
  {
    jd[e[p][i]]++;
    f(p + 1, jd);
    jd[p]++;
    REP2(j, i + 1, e[p].size())
    {
      jd[e[p][j]]++;
      f(p + 1, jd);
      jd[e[p][j]]--;
    }
    jd[p]--;
    jd[e[p][i]]--;
  }
  jd[p]--;

  return;
}

int main()
{
  int m;
  cin >> n >> m;
  e.resize(n);

  REP(i, m)
  {
    int a, b;
    cin >> a >> b;
    e[a - 1].push_back(b - 1);
  }
  V jd(n);
  f(0, jd);

  cout << ans << endl;

  return 0;
}