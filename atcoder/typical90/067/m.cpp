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

ll pow(ll a, ll b)
{
  ll sum = 1;
  REP2(i, 1, b + 1)
  {
    sum *= a;
  }
  return sum;
}

int main()
{
  ll tn, n;
  int k;
  ll ans;
  cin >> n >> k;
  tn = n;

  ll cnt = 0;

  REP(i, k)
  {
    if (0 < i)
    {
      tn = ans;
    }

    ll n10 = 0;
    cnt = 0;
    while (0 < tn)
    {
      n10 += (tn % 10) * pow(8L, cnt);
      tn /= 10;
      cnt++;
    }

    ll n9 = 0;
    cnt = 0;
    while (0 != n10 / 9)
    {
      n9 += n10 % 9 * pow(10, cnt);
      n10 /= 9;
      cnt++;
    }
    n9 += n10 % 9 * pow(10, cnt);

    ll cnt2 = 0;
    ans = 0;
    while (0 < n9)
    {
      int a = n9 % 10;
      if (a == 8)
      {
        a = 5;
      }
      ans += a * pow(10, cnt2);
      n9 /= 10;
      cnt2++;
    }
  }
  cout << ans << endl;
  return 0;
}