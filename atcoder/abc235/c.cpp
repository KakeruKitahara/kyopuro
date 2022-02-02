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
  int n, q;
  map<pair<int, int>, int> mp;
  map<int, int> mp2;
  cin >> n >> q;
  V a(n), x(q), k(q);
  REP(i, n)
  {
    cin >> a[i];
    mp2[a[i]]++;
    mp[make_pair(a[i], mp2[a[i]])] = i + 1;
  }
  REP(i, q)
  {
    cin >> x[i] >> k[i];
  }

  REP(i, q)
  {
    int b = mp[make_pair(x[i], k[i])];
    b = b == 0 ? -1 : b;
    cout << b << endl;
  }

  return 0;
}