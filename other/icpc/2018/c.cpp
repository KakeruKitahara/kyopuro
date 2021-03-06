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

void solve(int a)
{

  int l = 1;
  ll sum = 0;
  int ans = -1, ind = -1;
  REP2(r, 1, 1000000000)
  {
    sum += r;
    while (sum > a)
    {
      sum -= l;
      l++;
    }

    if (sum == a)
    {
      if (ans < r - l + 1)
      {
        ind = l;
        ans = r - l + 1;
      }
    }
  }

  cout << ind << " " << ans << endl;
}

int main()
{
  while (1)
  {
    int a;
    cin >> a;
    if (a == 0)
    {
      break;
    }
    solve(a);
  }

  return 0;
}