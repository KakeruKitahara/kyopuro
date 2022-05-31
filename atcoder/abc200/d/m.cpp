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
  V a(n);
  REP(i, n)
  {
    int c;
    cin >> c;
    a[i] = c % 200;
  }

  multiset<pair<int, V>> bc;

  for (int bit = 0; bit < (1 << min(n, 9)); bit++)
  {
    V t;
    int sum = 0;
    if (bit != 0)
    {
      for (int i = 0; i < min(n, 9); i++)
      {
        if (bit & (1 << i))
        {
          t.push_back(i);
          sum += a[i];
          sum %= 200;
        }
      }
      bc.insert(make_pair(sum, t));
    }
  }
  auto last = bc.end();
  last--;

  V b, c;

  for (auto it = bc.begin(); it != last; it++)
  {
    auto it2 = it;
    it2++;
    if (it->first == it2->first)
    {
      b = it->second;
      c = it2->second;
      break;
    }
  }

  if (b.size() == 0 && c.size() == 0)
  {
    cout << "No" << endl;
  }
  else
  {
    cout << "Yes" << endl;
    cout << b.size() << " ";
    REP(i, b.size())
    {
      cout << b[i] + 1 << " ";
    }
    cout << endl;
    cout << c.size() << " ";
    REP(i, c.size())
    {
      cout << c[i] + 1 << " ";
    }
    cout << endl;
  }

  return 0;
}