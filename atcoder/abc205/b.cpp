#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using V = vector<int>;
using VV = vector<vector<int>>;
using P = pair<int, int>;
using S = string;
using ll = long long;
constexpr int INF = 1000000000 + 8;

int main()
{
  int n;
  cin >> n;
  V a(n);
  REP(i, n)
  {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  int flag = 0;
  int i = 0;
  REP(j, n)
  {
    if (a[j] != i + 1)
    {
      flag = 1;
      break;
    }
    i++;
  }

  if (flag == 1)
  {
    cout << "No" << endl;
  }
  else
  {
    cout << "Yes" << endl;
  }

  return 0;
}