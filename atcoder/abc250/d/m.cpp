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

  ll n;
  cin >> n;

  Vl pr;
  for (int i = 2; i <= 1000000; i++)
  {
    bool flag = true;
    for (int j = 2; j * j <= i; j++)
    {
      if (i % j == 0)
      {
        flag = false;
        break;
      }
    }
    if (flag)
    {
      pr.push_back(i);
    }
  }

  Vl p3;

  REP(i, pr.size())
  {
    p3.push_back(pr[i] * pr[i] * pr[i]);
  }

  ll ans = 0;
  REP(i, p3.size())
  {
    int j = 0;
    while (pr[j] < pr[i])
    {
      if(pr[j] > LINF / p3[i]){
        break;
      }
      if(pr[j] * p3[i] <= n){
        ans++;
      }
      j++;
    }
  }

  cout << ans << endl;

  return 0;
}