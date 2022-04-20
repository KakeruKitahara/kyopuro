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
  ll c;
  cin >> n >> c;
  vector<P> ab;
  V c2(n);
  REP(i, n)
  {
    int a, b;
    cin >> a >> b >> c2[i];
    ab.push_back(make_pair(a, i));
    ab.push_back(make_pair(b + 1, i));
  }

  sort(ab.begin(), ab.end());

  map<int, bool> jd;
  ll s = 0;
  int day = 0;
  vector<pair<ll, int>> sum;
  REP(i, ab.size())
  {
    if (jd[ab[i].second] == 0)
    {
      s += c2[ab[i].second];
      jd[ab[i].second] = 1;
    }
    else
    {
      s -= c2[ab[i].second];
    }
    if (i == ab.size() - 1)
    {
      break;
    }
    if (ab[i].first != ab[i + 1].first)
    {
      sum.push_back(make_pair(s, ab[i + 1].first - ab[i].first));
    }
  }

  sort(sum.begin(), sum.end());

  int t = sum.size();
  REP(i, sum.size())
  {
    if (sum[i].first > c)
    {
      t = i;
      break;
    }
  }
  ll ans = 0;
  REP(i, sum.size())
  {
    if (t > i)
    {
      ans += sum[i].first * sum[i].second;
    }
    else
    {
      ans += c * sum[i].second;
    }
  }
  cout << ans << endl;
  return 0;
}