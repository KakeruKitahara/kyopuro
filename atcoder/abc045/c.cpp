#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= n; i--)
#define REPR2(i, a, n) for (int i = a; 0 <= n; i--)
using V = vector<int>;
using S = string;
using P = pair<int, int>;
using ll = long long;
using namespace std;

int main()
{
  S s;
  cin >> s;

  ll ans = 0;

  string ss;
  ll sum;
  for (int bit = 0; bit < (1 << (s.size() - 1)); bit++) // 1 << n = 2^n通り.
  {
    sum = 0;
    for (int i = 0; i < s.size() - 1; i++)
    { // bit桁までi桁を調べる.
      if (bit & (1 << i))
      {
        if (ss.empty())
        {
          ll a = s[i] - '0';
          sum += a;
        }
        else
        {
          ss += s[i];
          ll a = atoll(ss.c_str());
          sum += a;
          ss.clear();
        }
      }
      else
      {
        ss += s[i];
      }
    }

    ss += s[s.size() - 1];
    ll a = atoll(ss.c_str()); // int以上になるのでstroll関数を用いる.
    sum += a;
    ss.clear();

    ans += sum;
    }

  cout << ans << endl;
  return 0;
}