#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

/* macro */
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
using V = vector<int>;
using VV = vector<vector<int>>;
using VVV = vector<vector<vector<int>>>;
using Vl = vector<long long>;
using VVl = vector<vector<long long>>;
using VVVl = vector<vector<vector<long long>>>;
using P = pair<int, int>;
using VP = vector<pair<int, int>>;
using VVP = vector<vector<pair<int, int>>>;
using S = string;
using VS = vector<string>;
using VVS = vector<vector<string>>;
using ll = long long;
constexpr int IINF = 1000000000 + 8;
constexpr long long LINF = 1000000000000000000LL + 8;
using mint = modint1000000007;

int n;

map<int, int> a;
V ans;

void dfs(int p, int cnt)
{
  ans[p - 1] = cnt;
  if (a.count(a[p] * 2) != 0)
  {
    dfs(a[p] * 2, cnt + 1);
  }
  else
  {
    ans[a[p] * 2 - 1] = cnt + 1;
  }
  if (a.count(a[p] * 2 + 1) != 0)
  {
    dfs(a[p] * 2 + 1, cnt + 1);
  }
  {
    ans[a[p] * 2] = cnt + 1;
  }
}

int main()
{
  cin >> n;
  REP(i, n)
  {
    int b;
    cin >> b;
    a[b] = i + 1;
  }
  ans.resize(2 * n + 1);

  dfs(1, 0);

  REP(i, 2 * n + 1)
  {
    cout << ans[i] << endl;
  }

  return 0;
}