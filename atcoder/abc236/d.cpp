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
  vector<vector<ll>> a(2 * n - 1);

  REP(i, 2 * n - 1)
  {
    REP(j, 2 * n - 1 - i)
    {
      ll b;
      cin >> b;
      a[i].push_back(b);
    }
  }

  V v(2 * n);
  REP(i, v.size())
  {
    v[i] = i + 1;
  }

  do{
    if(v[i] % )
  }while(next_permutation(v.begin(), v.end()));

  return 0;
}