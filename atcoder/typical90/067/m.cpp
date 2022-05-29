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
  S n;
  int k;
  cin >> n >> k;
  S ns8 = n;

  REP(j, k)
  {
    V nv;
    int lala = ns8.size();
    REP(i, lala)
    {
      nv.push_back(ns8.back() - '0');
      ns8.pop_back();
    }
    reverse(nv.begin(), nv.end());
    V n10(20);
    
    ll d = 1;
    REPR(i, nv.size())
    {
      int k = nv[i];
      ll t = d * k;
      int l = 19;
      while (t != 0)
      {
        n10[l] += t % 10;
        t /= 10;

        l--;
      }
      d *= 8;
    }
    REPR2(i, n10.size(), 1)
    {
      n10[i - 1] += n10[i] / 10;
      n10[i] = n10[i] % 10;
    }
    d = 1;
    ll n8 = 0, n102 = 0;
    ;
    REPR(i, 20)
    {
      n102 += d * n10[i];
      d *= 10;
    }
    d = 1;
    while (n102 != 0)
    {
      ll k = n102 % 9;
      n8 += d * k;
      n102 /= 9;
      d *= 10;
    }

    ns8 = to_string(n8);

    REP(i, ns8.size())
    {
      if (ns8[i] == '8')
      {
        ns8[i] = '5';
      }
    }
  }
  cout << ns8 << endl;

  return 0;
}