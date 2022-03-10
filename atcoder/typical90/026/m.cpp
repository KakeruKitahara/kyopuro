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
VV e;
V bo;
V ans1, ans2;
int s = 0;

void dfs(int p, int ni)
{
  bo[p] = 1;

  if (ni)
  {
    ans1.push_back(p);
  }
  else
  {
    ans2.push_back(p);
  }

  if (e[p].size() == 1 && s == 1)
  {
    return;
  }

  s = 1;

  REP(i, e[p].size())
  {
    if (bo[e[p][i]] == 0)
    {
      dfs(e[p][i], (ni + 1) % 2);
    }
  }

  return;
}

int main()
{
  int n;
  cin >> n;
  e.resize(n + 1);
  bo.resize(n + 1);
  REP(i, n - 1)
  {
    int a, b;
    cin >> a >> b;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  dfs(1, 0);

  if (ans1.size() < ans2.size())
  {

    REP(i, n / 2)
    {
      cout << ans2[i] << " ";
    }
  }
  else
  {
    REP(i, n / 2)
    {
      cout << ans1[i] << " ";
    }
  }
  cout << endl;

  return 0;
}