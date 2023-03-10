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
  int k;
  cin >> k;
  if (k % 2 == 0 || k % 5 == 0)
  {
    cout << -1 << endl;
  }
  else
  {
    int s = 7;
    int cnt = 1;
    while (s % k != 0)
    {
      int a = s % k;
      s = a * 10 + 7;
      cnt++;
    }

    cout << cnt << endl;
  }

  return 0;
}