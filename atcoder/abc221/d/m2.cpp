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
  int n;
  cin >> n;

  vector<P> ab(n);

  REP(i, n)
  {
    cin >> ab[i].second >> ab[i].first;
    ab[i].first = ab[i].second + ab[i].first - 1;
  }

  sort(ab.begin(), ab.end());

  V ans(n);
  int s = 0, i = 0;
  int person = 0;
  while (i != n - 1)
  {
    if (ab[i].first + ab[i].second < ab[i + 1].first)
    {
      ans[person] += ab[i].first + ab[i].second - s - 2;
      person--;
      i++;
    }
    else
    {
      ans[person] += ab[i].first + ab[i + 1].first - s - 2;
      person++;
    }
  }

  REP(i, n)
  {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}