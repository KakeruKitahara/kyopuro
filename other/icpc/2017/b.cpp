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

void solve(S a)
{
  S b;
  cin >> b;
  vector<S> as;
  vector<S> as2;
  vector<S> bs;
  vector<S> bs2;
  int cnt = 0;
  S tmp;
  REP(i, a.size())
  {
    if (a[i] == '\"')
    {
      cnt++;
      if (cnt % 2 == 0)
      {
        as.push_back(tmp);
        tmp.clear();
      }
      else
      {
        as2.push_back(tmp);
        tmp.clear();
      }
      continue;
    }

    tmp.push_back(a[i]);
  }
  if (tmp.size() != 0)
  {
    as2.push_back(tmp);
    tmp.clear();
  }

  cnt = 0;
  REP(i, b.size())
  {
    if (b[i] == '\"')
    {
      cnt++;
      if (cnt % 2 == 0)
      {
        bs.push_back(tmp);
        tmp.clear();
      }
      else
      {
        bs2.push_back(tmp);
        tmp.clear();
      }
      continue;
    }

    tmp.push_back(b[i]);
  }
  if (tmp.size() != 0)
  {
    bs2.push_back(tmp);
  }

  if (a == b)
  {
    cout << "IDENTICAL" << endl;
    return;
  }

  if (as2.size() != bs2.size() || as.size() != bs.size())
  {
    cout << "DIFFERENT" << endl;
    return;
  }

  REP(i, as2.size())
  {
    if (as2[i] != bs2[i])
    {
      cout << "DIFFERENT" << endl;
      return;
    }
  }

  cnt = 0;

  REP(i, as.size())
  {
    if (as[i] != bs[i])
    {
      cnt++;
    }
  }

  if (cnt == 1)
  {
    cout << "CLOSE" << endl;
    return;
  }
  cout << "DIFFERENT" << endl;
}

int main()
{
  while (1)
  {
    S a;
    cin >> a;
    if (a == ".")
    {
      break;
    }

    solve(a);
  }

  return 0;
}