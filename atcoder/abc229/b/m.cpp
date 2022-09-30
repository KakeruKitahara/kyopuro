#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using V = vector<int>;
using VV = vector<vector<int>>;
using P = pair<int, int>;
using S = string;
using ll = long long;
constexpr int INF = 1000000000 + 8;
using mint = modint1000000007;

int main()
{
  ll a, b;
  cin >> a >> b;
  while (a > 0 || b > 0)
  {
    if (9 < a % 10 + b % 10)
    {
      cout << "Hard" << endl;
      return 0;
    }
    a /= 10;
    b /= 10;
  }
  cout << "Easy" << endl;
  return 0;
}