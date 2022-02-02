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
  S s;
  cin >> s;

  int cnt = 0, cnt2 = 0;
  REPR(i, s.size())
  {
    if (s[i] == 'a')
    {
      cnt++;
    }
    else
      break;
  }

  REP(i, s.size())
  {
    if (s[i] == 'a')
    {
      cnt2++;
    }
    else
      break;
  }

  int k = s.size() - cnt;
  int j = 0;
  if (cnt < cnt2)
  {
    cout << "No" << endl;
    return 0;
  }
  REP2(i, cnt2, k)
  {
    if (s[i] != s[k - 1 - j])
    {
      cout << "No" << endl;
      return 0;
    }
    j++;
    if (i == j)
    {
      break;
    }
  }
  cout << "Yes" << endl;
  return 0;
}