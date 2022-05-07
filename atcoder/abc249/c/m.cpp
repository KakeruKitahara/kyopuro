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
  int n, k;
  cin >> n >> k;
  vector<S> s(n);

  REP(i, n)
  {
    cin >> s[i];
  }

  int ans = 0;
  for (int bit = 0; bit < (1 << n); bit++) // 1 << n = 2^n通り.
  {
    V st;
    V a(1000);
    int in = 0;
    for (int i = 0; i < n; i++)
    { // bit桁までi桁を調べる.
      if (bit & (1 << i))
      {
        st.push_back(i);
      }
    }

    REP(i, st.size())
    {
      REP(j, s[st[i]].size())
      {
        a[s[st[i]][j]]++;
      }
    }

    REP(i, 1000)
    {
      if (a[i] == k)
      {
        in++;
      }
    }

    ans = max(ans, in);
  }
  cout << ans << endl;

  return 0;
}