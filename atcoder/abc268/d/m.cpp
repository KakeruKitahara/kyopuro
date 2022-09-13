#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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

  int n, m;
  cin >> n >> m;
  VS s(n);
  set<S> t;
  REP(i, n)
  {
    cin >> s[i];
  }
  REP(j, m)
  {
    S tmp;
    cin >> tmp;
    t.insert(tmp);
  }

  if (n == 1)
  {
    if (s[0].size() < 3)
    {
      cout << -1 << endl;
      return 0;
    }
    if (t.count(s[0]) == 0)
    {
      cout << s[0] << endl;
    }
    else
    {
      cout << -1 << endl;
    }
    return 0;
  }
  sort(s.begin(), s.end());
  do
  {
    S a;
    REP(i, s.size())
    {
      a += s[i];
      if (i == s.size() - 1)
        continue;
      a.push_back('_');
    }
    REP(i, a.size())
    {
  
      if (a[i] == '_')
      {
        S ss;
        S tt;

        REP(j, i + 1)
        {
          ss.push_back(a[j]);
        }
        REP2(j, i + 1, a.size())
        {
          tt.push_back(a[j]);
        }
        while (ss.size() + tt.size() != 17)
        {
          S search = ss + tt;
  

          ss.push_back('_');
        }
      }
    }

  } while (next_permutation(s.begin(), s.end()));
  cout << -1 << endl;
  return 0;
}