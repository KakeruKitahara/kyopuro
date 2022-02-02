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
  int flag;
  int n;
  cin >> n;
  V a(n);
  map<int, int> cnt;

  REP(i, n)
  {
    cin >> a[i];
    cnt[a[i]] = 1;
  }

  int r = a[0];
  REP2(i, 1, n)
  {
    r ^= a[i];
  }

  REP(i, n)
  {
    if (cnt[r] == 1)
    {
      if (i % 2)
        flag = 2;
      else
        flag = 1;
      break;
    }
    else{
      
    }
  }

  cout << (flag == 1) ? "Win" : "Lose";

  return 0;
}