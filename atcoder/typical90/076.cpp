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

int main()
{
  int n;
  cin >> n;
  V a(n);
  REP(i, n)
  {
    cin >> a[i];
  }

  ll sum2 = 0;

  REP(i, n)
  {
    sum2 += a[i];
  }

  if (sum2 % 10 != 0)
  {
    cout << "No" << endl;
    return 0;
  }

  vector<ll> sum(2 * n + 1);

  int j = 0;
  REP2(i, 1, 2 * n + 1)
  {
    j++;
    sum[i] = sum[i - 1] + a[j - 1];
    if (i == n)
    {
      j = 0;
    }
  }

  int l = 1, r = 1;
  while (l != 2 * n)
  {
     if (sum[r] - sum[l - 1] == sum2 / 10)
    {
      cout << "Yes" << endl;
      return 0;
    }
    else
    if (r == 2 * n)
    {
      l++;
    }
    else if (sum[r] - sum[l - 1] < sum2 / 10 || l == r)
    {
      r++;
    }
    else if (sum[r] - sum[l - 1] > sum2 / 10)
    {
      l++;
    }
  }

  cout << "No" << endl;
  return 0;
}