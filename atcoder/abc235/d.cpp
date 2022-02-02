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
constexpr int INF = 1000000000 + 8;
using mint = modint1000000007;
vector<ll> an;
int a;

int pow10(int a)
{
  int b = 1;
  REP(i, a)
  {
    b *= 10;
  }
  return b;
}

int dfs(int rn, int ans)
{
  int ke = 0;
  int tn = rn;
  while (tn != 0)
  {
    tn /= 10;
    ke++;
  }

  if(rn % a == 0){
    ans = min(ans , ?);
  }

  REP(i, ke)
  {
    if (rn % 10 == 0)
      continue;

    rn = rn % 10 * pow10(ke - 1) + rn / 10;
    ans = dfs(rn % 10 * pow10(ke - 1) + rn / 10, ans);
  }
}

int main()
{
  int n;
  cin >> a >> n;

  an.push_back(1);
  int ans = INF, cnt = 0;

  int rn = n;

  if (ans == INF)
  {
    cout << -1 << endl;
  }
  else
  {
    cout << ans << endl;
  }

  return 0;
}