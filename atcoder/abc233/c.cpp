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
V l;
vector<vector<ll>> a;
int n;
ll x;

int loop(int ptr, ll sum)
{
  int ans = 0;

  if (ptr == n - 1)
  {
    REP(i, l[ptr])
    {
      if (sum < (1000000000000000001LL + a[ptr][i] - 1) / a[ptr][i] && sum * a[ptr][i] == x)
      {
        ans++;
      }
    }

    return ans;
  }

  REP(i, l[ptr])
  {
    if (sum < (1000000000000000001LL + a[ptr][i] - 1) / a[ptr][i])
    {
      ans += loop(ptr + 1, sum * a[ptr][i]);
    }
  }

  return ans;
}

int main()
{

  cin >> n >> x;
  l.resize(n);
  a.resize(n);
  REP(i, n)
  {
    cin >> l[i];
    a[i].resize(l[i]);
    REP(j, l[i])
    {
      cin >> a[i][j];
    }
  }

  int ans = 0;
  REP(i, l[0])
  {
    ans += loop(1, a[0][i]);
  }
  cout << ans << endl;
  return 0;
}