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
VV e;
vector<P> od;

int main()
{
  int n, q;
  V x(n);
  REP(i, n)
  {
    cin >> x[i];
  }

  e.resize(n + 1);
  REP(i, n - 1)
  {
    int a, b;
    cin >> a >> b;
    e[a].push_back(b);
    e[b].push_back(a);
  }

  V tmp = 

  V v, k;
  REP(i, q)
  {
    cin >> v[i] >> k[i];
  }

  od.resize(n + 1);

  REP(i, q)
  {
    od[v[i]] = make_pair(k[i], i);
  }



  return 0;
}