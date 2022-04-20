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
  vector<P> ab;

  REP(i, n)
  {
    int a, b;
    cin >> a >> b;
    ab.push_back(make_pair(a, 0));
    ab.push_back(make_pair(a + b, 1));
  }

  sort(ab.begin(), ab.end());
  int ptr = 1;
  V ans(n + 1);
  int d = 0;
  REP(i, ab.size())
  {
    ans[d] += ab[i].first - ptr;
    if (ab[i].second == 0)
    {
      d++;
    }
    else
    {
      d--;
    }

    ptr = ab[i].first;
  }

  REP2(i, 1, n + 1)
  {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}