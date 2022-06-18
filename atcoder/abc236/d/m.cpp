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
VVl a;

ll f(int ptr, ll sum, ll jd)
{
  if (ptr == 2 * n - 1)
  {
    return sum;
  }

  ll ans = -1;

  if (jd & (1 << ptr))
  {
    ans = max(ans, f(ptr + 1, sum, jd));
  }
  else
  {
    REP(i, a[ptr].size())
    {
      if (!(jd & (1 << (ptr + i + 1))))
      {
        ans = max(ans, f(ptr + 1, sum ^ a[ptr][i], jd + (1 << (ptr + i + 1))));
      }
    }
  }
  return ans;
}

int main()
{
  cin >> n;
  a.resize(2 * n - 1);

  int b = n;
  REP(i, 2 * n - 1)
  {
    a[i].resize(2 * n - 1 - i);
    REP(j, 2 * n - 1 - i)
    {
      cin >> a[i][j];
    }
  }

  cout << f(0, 0, 0) << endl;
  return 0;
}