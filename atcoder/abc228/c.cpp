#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using V = vector<int>;
using VV = vector<vector<int>>;
using P = pair<int, int>;
using S = string;
using ll = long long;
constexpr int INF = 1000000000 + 8;
using mint = modint1000000007;

int main()
{
  int n, k;
  cin >> n >> k;
  VV p(n, V(3));
  vector<pair<int, int>> sum(n);
  REP(i, n)
  {
    sum[i].first = 0;
    REP(j, 3)
    {
      cin >> p[i][j];
      sum[i].second = i;
      sum[i].first += p[i][j];
    }
  }

  vector<pair<int, int>> sum2 = sum;

  sort(sum.rbegin(), sum.rend());

  REP(i, n)
  {
    if (sum[k - 1].first > sum2[i].first + 300)
    {
      cout << "No" << endl;
    }
    else
    {
      cout << "Yes" << endl;
    }
  }

  return 0;
}