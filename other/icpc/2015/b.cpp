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

  V b;
  REP(i, a)
  {
    S s;
    cin >> s;
    b.push_back(s.size());
  }

  REP(i, b.size())
  {
    int cnt = 0;
    int sum = 0;
    REP2(j, i, b.size())
    {
      sum += b[j];
      if (cnt == 0 || cnt == 2)
      {
        if (sum > 5)
        {
          break;
        }
        else if (sum == 5)
        {
          cnt++;
          sum = 0;
        }
      }
      else
      {
        if (sum > 7)
        {
          break;
        }
        else if (sum == 7)
        {
          cnt++;
          sum = 0;
          if (cnt == 5)
          {
            break;
          }
        }
      }
    }

    if (cnt == 5)
    {
      cout << i + 1 << endl;
      return;
    }
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