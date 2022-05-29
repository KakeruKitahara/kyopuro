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
  map<int, int> ma1;
  unordered_map<int, int> ma2;

  ll sum = 0;
  REP(i, n)
  {
    int a;
    cin >> a;

    ma1[a]++;
  }

  V mav;

  for (P k : ma1)
  {
    sum += k.second;
    mav.push_back(k.second);
    ma2[k.second]++;
  }

  V skip;
  sort(mav.begin(), mav.end());

  skip.push_back(0);
  REP(k, mav.size() - 1)
  {
    if (mav[k] != mav[k + 1])
    {
      skip.push_back(k + 1);
    }
  }

  ll ans = 0;
  int i2 = 0;
  REP(i, mav.size())
  {

    if (0 < i && mav[i - 1] == mav[i])
    {
      i2++;
    }
    ll sum2 = sum;
    for (int j = i2; j < skip.size(); j++)
    {
      ll sum3 = sum2 - mav[j] - mav[i];
      int kk = ma2[mav[j]];
      if (mav[j] == mav[i])
      {
        kk--;
      }
      ans += sum3 * kk * mav[i];
      sum2 -= mav[j];
    }
    sum -= mav[i];
  }

  cout << ans << endl;

  return 0;
}