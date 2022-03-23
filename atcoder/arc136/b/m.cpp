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
  V a(n), b(n);
  V ca(5001), cb(5001);

  REP(i, n)
  {
    cin >> a[i];
    ca[a[i]]++;
  }
  REP(i, n)
  {
    cin >> b[i];
    cb[b[i]]++;
  }

  REP2(i, 1, 5001)
  {
    if (ca[i] != cb[i])
    {
      cout << "No" << endl;
      return 0;
    }
  }

  REP2(i, 1, 5001)
  {
    if (2 <= ca[i])
    {
      cout << "Yes" << endl;
      return 0;
    }
  }

  unordered_map<int, int> ma, mb;
  int j = 0;

  REP2(i, 1, 5001)
  {
    if (ca[i] == 1)
    {
      ma[i] = j;
      j++;
    }
  }

  j = 0;
  REP2(i, 1, 5001)
  {
    if (cb[i] == 1)
    {
      mb[i] = j;
      j++;
    }
  }

  REP(i, n)
  {
    a[i] = ma[a[i]];
    b[i] = mb[b[i]];
  }

  dsu da(n), db(n);
  set<int> sa, sb;
  REP(i, n)
  {
    da.merge(i, a[i]);
  }

  REP(i, n)
  {
    sa.insert(da.leader(i));
  }

  REP(i, n)
  {
    db.merge(i, b[i]);
  }

  REP(i, n)
  {
    sb.insert(db.leader(i));
  }

  int circlea = sa.size(), circleb = sb.size();

  if (circlea % 2 == circleb % 2)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  return 0;
}