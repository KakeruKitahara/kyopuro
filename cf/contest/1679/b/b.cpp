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

int main()
{
  int n, q;
  cin >> n >> q;
  map<P, ll> mp;
  ll ans = 0;
  REP(i, n)
  {
    cin >> mp[make_pair(0, i)];
    ans += mp[make_pair(0, i)];
  }
  Vl t(q), t2(q), t11(q), t12(q);
  REP(i, q)
  {
    cin >> t[i];
    if (t[i] == 1)
    {
      cin >> t11[i] >> t12[i];
      t11[i]--;
    }
    else
    {
      cin >> t2[i];
    }
  }

  ll ze = -1;
  int cnt = 0;
  REP(i, q)
  {
    if (t[i] == 1)
    {
      if (mp.count(make_pair(cnt, t11[i])))
      {
        ans += t12[i] - mp[make_pair(cnt, t11[i])];
        mp[make_pair(cnt, t11[i])] = t12[i];
      }
      else{
        ans += t12[i] - ze;
         mp[make_pair(cnt, t11[i])] = t12[i];
      }
    }
    else
    {
      ze = t2[i];
      ans = ze * n;
      cnt++;
    }
    cout << ans << endl;
  }

  return 0;
}