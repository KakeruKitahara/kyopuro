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

  V a;
  while (n)
  {
    a.push_back(n % 10);
    n /= 10;
  }

  sort(a.begin(), a.end());

  int r = a.size() / 2;
  ll ans = -1;

  do
  {
    int digit = 1;
    int rrl = 0, lll = 0;
    REP(i, r)
    {
      rrl += digit * a[i];
      digit *= 10;
    }

    digit = 1;
    REP2(i, r, a.size())
    {
      lll += digit * a[i];
      digit *= 10;
    }

    ll tmp = (ll)rrl * lll;
    ans = tmp < ans ? ans : tmp;
  } while (next_permutation(a.begin(), a.end()));

  cout << ans << endl;

  return 0;
}