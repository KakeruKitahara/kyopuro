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
  S s;
  cin >> s;

  ll sum = 0;
  int size = s.size();

  REP(i, size)
  {
    sum += s[i] - '0';
  }

  Vl c(size);
  S ans;

  REPR(i, size)
  {
    ll tmp = 0;
    if (i != size - 1)
    {
      sum -= s[i + 1] - '0';
      if (0 <= i - size + 1)
      {
        sum += s[i - 1] - '0';
      }
      tmp += c[i + 1];
    }
    tmp += sum;

    int skip = 0;
    while (tmp)
    {
      int l = tmp % 10;
      if (skip == 0)
        ans += to_string(l);
      tmp /= 10;
      if (skip != 0)
        c[i + 1 - skip] += l;
      skip++;
    }
  }
  if (c[0] != 0)
    ans += to_string(c[0]);

  reverse(ans.begin(), ans.end());
  cout << ans << endl;

  return 0;
}