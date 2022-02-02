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
  int r, c, r2, c2;
  cin >> r >> c >> r2 >> c2;

  if (r == r2 && c == c2)
  {
    cout << 0 << endl;
    return 0;
  }

  if (r + c == r2 + c2 || r - c == r2 - c2 || abs(r - r2) + abs(c - c2) <= 3)
  {
    cout << 1 << endl;
    return 0;
  }

  if ((r2 - r + c2 - c) % 2 == 0 ||  abs(r - r2) + abs(c - c2) <= 6)
  {
    cout << 2 << endl;
    return 0;
  }

  REP2(i, -3, 4)
  {
    if (r - r2 + c - c2 == i)
    {
      cout << 2 << endl;
      return 0;
    }
  }

  REP2(i, -3, 4)
  {
    if (r - r2 - (c - c2) == i)
    {
      cout << 2 << endl;
      return 0;
    }
  }

  cout << 3 << endl;
  return 0;
}