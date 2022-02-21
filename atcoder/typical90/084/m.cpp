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
  S s;
  cin >> s;

  Vl c;
  ll cnt = 0;
  REP2(i, 1, n)
  {
    if (s[i - 1] == s[i])
    {
      cnt++;
    }
    else
    {
      c.push_back(cnt);
      cnt = 0;
    }
  }
  if (cnt != 0)
  {
    c.push_back(cnt);
  }

  ll u = (s.size() - 1) * s.size() / 2;
  ll mi = 0;
  REP(i, c.size())
  {
    mi += c[i] * (c[i] + 1) / 2;
  }

  cout << u - mi << endl;
  return 0;
}