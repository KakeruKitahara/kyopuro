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
  S s;
  cin >> s;
  V l, r;
  int la = 0;
  REP(i, n)
  {
    if (s[i] == 'L')
    {
      l.push_back(i);
      la = 1;
    }
    else
    {
      r.push_back(i);
      la = 2;
    }
  }

  if (la == 1)
  {
    l.push_back(n);
  }
  else
  {
    r.push_back(n);
  }

  REP(i, r.size())
  {
    cout << r[i] << " ";
  }
  REPR(i, l.size())
  {
    cout << l[i] << " ";
  }

  cout << endl;
  return 0;
}