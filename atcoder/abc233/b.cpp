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
  S s;
  int l, r;
  cin >> l >> r >> s;
  vector<S> k(3);

  k[0] = s.substr(0, l - 1);
  k[1] = s.substr(l - 1, r - l + 1);
  k[2] = s.substr(r);

  reverse(k[1].begin(), k[1].end());

  REP(i, k.size())
  {
    cout << k[i];
  }
  cout << endl;

  return 0;
}