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
  int n, k;
  cin >> n >> k;

  int sumn = 0, sumk = 0;

  int sum = 0;
  REP2(i, 1, n + 1)
  {
    REP2(j, 1, k + 1)
    {
      int a = i * 100 + j;
      sum += a;
    }
  }

  cout << sum;
  return 0;
}