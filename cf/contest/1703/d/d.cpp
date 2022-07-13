#include <bits/stdc++.h>
using namespace std;
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

void solve()
{
  int n;
  cin >> n;
  vector<S> s(n);

  map<S, int> mp;
  REP(i, n)
  {
    cin >> s[i];
    mp[s[i]] = 1;
  }
  S ans;
  REP(i, n)
  {
    int f = 0;
    S a, b;
    a += s[i][0];
    REP2(j, 1, s[i].size())
    {
      b += s[i][j];
    }
    REP2(j, 1, s[i].size())
    {
      if (mp[a] == 1 && mp[b] == 1)
      {
        ans += '1';
        f = 1;
        break;
      }
      a += s[i][j];
      b.erase(0, 1);
    }
    if (f == 0)
    {
      ans += '0';
    }
  }

  cout << ans << endl;
}

int main()
{
  int t;
  cin >> t;
  REP(i, t)
  {
    solve();
  }
  return 0;
}