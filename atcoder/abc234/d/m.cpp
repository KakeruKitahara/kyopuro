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
  int n, k;
  cin >> n >> k;
  V p(n);
  REP(i, n)
  {
    cin >> p[i];
  }

  set<int> tp;
  REP(i, k)
  {
    tp.insert(p[i]);
  }
  auto it = tp.begin();
  cout << *it << endl;

  REP2(i, k, n)
  {
    if (*it < p[i])
    {
      tp.insert(p[i]);
      it++;
    }
    else
    {
      tp.insert(p[i]);
    }

    cout << *(it) << endl;
  }
  return 0;
}