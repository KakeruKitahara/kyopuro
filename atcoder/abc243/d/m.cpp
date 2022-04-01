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
  ll x;
  S s, s2;
  cin >> n >> x;
  int f = 0;
  cin >> s2;

  REP(i, n)
  {
    char tmp;
    tmp = s2[i];

    if (tmp != 'U')
    {
      s.push_back(tmp);
      f = 1;
    }
    else
    {
      if (s.back() == 'U' || s.size() == 0)
      {
        s.push_back(tmp);
      }
      else
      {
        s.pop_back();
      }
    }
  }
  ll ans = x;
  REP(i, s.size())
  {
    if (s[i] == 'U')
    {
      ans = ans / 2;
    }
    else if (s[i] == 'L')
    {
      ans = ans * 2;
    }
    else if (s[i] == 'R')
    {
      ans = ans * 2 + 1;
    }
  }

  cout << ans << endl;

  return 0;
}