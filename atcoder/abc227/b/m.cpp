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

int main()
{

  int n;
  cin >> n;
  V s(n);
  map<int, int> mp;
  REP(i, n)
  {
    cin >> s[i];
    mp[s[i]]++;
  }

  int ans = 0;
  REP2(a, 1, 1000)
  {
    REP2(b, 1, 1000)
    {
      if (mp[4 * a * b + 3 * a + 3 * b] > 0)
      {
        ans += mp[4 * a * b + 3 * a + 3 * b];
        mp[4 * a * b + 3 * a + 3 * b] = 0;
      }
    }
  }

  cout << n - ans << endl;
  return 0;
}