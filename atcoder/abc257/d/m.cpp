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
Vl x, y, p;
V jd;
VV ed;

void dfs(int ptr)
{

  jd[ptr] = 1;

  REP(i, ed[ptr].size())
  {
    if (jd[ed[ptr][i]] == 0)
    {
      dfs(ed[ptr][i]);
    }
  }
}

bool fx(ll m)
{
  ed.resize(n);

  REP(i, n)
  {
    REP(j, n)
    {
      if (i == j)
        continue;
      if (p[i] >= (abs(x[i] - x[j]) + abs(y[i] - y[j]) + m - 1) / m)
      {
        ed[i].push_back(j);
      }
    }
  }
  int cnt = 0;

  REP(i, n)
  {
    jd.resize(n);
    dfs(i);
    REP(i, n)
    {
      if (jd[i] == 1)
      {
        cnt++;
      }
    }
    if (cnt == n)
    {
      jd.clear();
      ed.clear();
      return true;
    }
    cnt = 0;
    jd.clear();
  }

  ed.clear();

  return false;
}

int main()
{
  cin >> n;
  x.resize(n);
  y.resize(n);
  p.resize(n);

  REP(i, n)
  {
    cin >> x[i] >> y[i] >> p[i];
  }

  ll left = 0, right = 10000000000LL;
  ll ans = 0;

  while (right - left > 1)
  {
    ll mid = left + (right - left) / 2;
    if (fx(mid) == true) // f(mid)の値とkeyを比較してkey以上だったらac
      right = mid;       // ac
    else
      left = mid; // wa
  }
  ans = right; // ansがacを満たす最小値となる．

  cout << ans << endl;

  return 0;
}