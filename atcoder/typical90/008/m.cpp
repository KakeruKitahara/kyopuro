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
  S s;
  cin >> s;
  S k = "atcoder";
  VV mp(7, V(7));
  vector<mint> at;
  int j = 0;
  int sum = 0;
  REP(i, n)
  {
    REP(j, k.size())
    {
      if (s[i] == k[j])
        mp[i][j] = mp[i - 1][j] + 1;
      else
        mp[i][j] = mp[i - 1][j];
    }
  }

  REP(i, n)
  {
    if (s[i] == 'a')
    {
      
    }
  }

  mint ans = 1;

  REP(i, at.size())
  {
    if ()
  }

  return 0;
}