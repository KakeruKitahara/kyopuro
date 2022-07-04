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

void solve(int a)
{
  vector<P> s;
  vector<S> c(a);
  set<char> ss;
  REP(i, a)
  {
    cin >> c[i];
    ss.insert(c[i][0]);
  }

  for (char z : ss)
  {
    s.push_back(make_pair(0, z - 'A'));
  }

  REP(i, a)
  {

    REP(j, s.size())
    {
      if (c[i][0] - 'A' == s[j].second)
      {
        s[j].first++;
      }
    }
    sort(s.begin(), s.end());

    if (a < s[s.size() - 1].first * 2)
    {
      cout << (char)(s[s.size() - 1].second + 'A') << " " << i + 1 << endl;
      return;
    }

    if (i >= 2 && s.size() > 1)
    {
      if (s[s.size() - 2].first + (a - i - 1) < s[s.size() - 1].first)
      {
        cout << (char)(s[s.size() - 1].second + 'A') << " " << i + 1 << endl;
        return;
      }
    }
  }

  if (s[s.size() - 2].first == s[s.size() - 1].first)
  {
    cout << "TIE" << endl;
  }
  else
  {
    cout << (char)(s[s.size() - 1].second + 'A') << " " << a << endl;
  }
}

int main()
{
  while (1)
  {
    int a;
    cin >> a;
    if (a == 0)
    {
      break;
    }
    solve(a);
  }

  return 0;
}