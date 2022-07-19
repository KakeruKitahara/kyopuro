#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
<<<<<<< HEAD
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
== == == =

/* macro */
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
             using V = vector<int>;
using VV = vector<vector<int>>;
using VVV = vector<vector<vector<int>>>;
using Vl = vector<long long>;
using VVl = vector<vector<long long>>;
using VVVl = vector<vector<vector<long long>>>;
using P = pair<int, int>;
using VP = vector<pair<int, int>>;
using VVP = vector<vector<pair<int, int>>>;
using S = string;
using VS = vector<string>;
using VVS = vector<vector<string>>;
using ll = long long;
constexpr int IINF = 1000000000 + 8;
constexpr long long LINF = 1000000000000000000LL + 8;
using mint = modint1000000007;

int main()
{
  S s, t;
  cin >> s >> t;
  VV sa(26);

  REP(i, s.size())
  {
    sa[s[i] - 'a'].push_back(i);
  }

  REP(i, t.size())
  {
    if (sa[t[i] - 'a'].size() == 0)
    {
      cout << -1 << endl;
      return 0;
    }
  }

  ll ans = sa[t[0] - 'a'][0];
  int now = sa[t[0] - 'a'][0];
  REP(i, t.size() - 1)
  {
    int tl = t[i] - 'a';
    int tr = t[i + 1] - 'a';

    auto it = upper_bound(sa[tr].begin(), sa[tr].end(), now);

    if (it == sa[tr].end())
    {
      ans += s.size() - now + sa[tr][0];
      now = sa[tr][0];
    }
    else
    {
      ans = *it + ans / s.size() * s.size();

      now = *it;
    }
  }

  cout << ans + 1 << endl;

  return 0;
}