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
  V x(n), y(n);
  S s;
  REP(i, n)
  {
    cin >> x[i] >> y[i];
  }
  cin >> s;

  map<pair<int, int>, set<int>> mp;

  REP(i, n)
  {
    if (s[i] == 'L')
    {
      mp[make_pair(y[i], 0)].insert(x[i]);
    }
    else
    {
      mp[make_pair(y[i], 1)].insert(x[i]);
    }
  }

  for (pair<pair<int, int>, set<int>> p : mp)
  {
    if (p.first.second == 1 && mp.count(make_pair(p.first.first, (p.first.second + 1) % 2)) != 0)
    {
      auto it = mp[make_pair(p.first.first, (p.first.second + 1) % 2)].end();
      it--;
      if (*it > *p.second.begin())
      {
        cout << "Yes" << endl;
        return 0;
      }
    }
    else if (p.first.second == 0 && mp.count(make_pair(p.first.first, (p.first.second + 1) % 2)) != 0)
    {
      auto it = mp[make_pair(p.first.first, (p.first.second + 1) % 2)].begin();
      auto it2 = p.second.end();
      it2--;
      if (*it < *it2)
      {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;

  return 0;
}