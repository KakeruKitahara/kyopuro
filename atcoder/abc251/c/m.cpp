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
  int n;
  cin >> n;

  map<pair<S, int>, int> mp;
  map<S, int> ss;

  REP(i, n)
  {
    S t;
    int a;

    cin >> t >> a;
    if (!ss.count(t))
    {
      mp[make_pair(t, i)] = a;
      ss[t] = 1;
    }
  }

  int max = -1;
  int ind;
  for (pair<pair<S, int>, int> a : mp)
  {
    if (max < a.second)
    {
      ind = a.first.second;
      max = a.second;
    }
  }

  cout << ind + 1 << endl;

  return 0;
}