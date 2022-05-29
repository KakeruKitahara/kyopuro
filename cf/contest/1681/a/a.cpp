#include <bits/stdc++.h>
using namespace std;
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

int main()
{

  int t;
  cin >> t;
  VV a(t), b(t);
  REP(i, t)
  {
    int n, m;
    cin >> n;
    a[i].resize(n);
    REP(j, n)
    {
      cin >> a[i][j];
    }
    cin >> m;
    b[i].resize(m);
    REP(j, m)
    {
      cin >> b[i][j];
    }
  }

  REP(i, t)
  {
    sort(a[i].rbegin(), a[i].rend());
    sort(b[i].rbegin(), b[i].rend());
  }

  REP(i, t)
  {
    if (a[i][0] > b[i][0])
    {
      cout << "Alice" << endl;
      cout << "Alice" << endl;
    }
    else if (a[i][0] < b[i][0])
    {
      cout << "Bob" << endl;
      cout << "Bob" << endl;
    }
    else
    {
      cout << "Alice" << endl;
      cout << "Bob" << endl;
    }
  }

  return 0;
}