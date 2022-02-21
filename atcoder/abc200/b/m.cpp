#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using V = vector<int>;
using P = pair<int, int>;
using S = string;
using ll = long long;

int main()
{
  ll n;
  int k;
  cin >> n >> k;
  REP(i, k)
  {
    if (n % 200 == 0)
    {
      n /= 200;
    }
    else
    {
      n *= 1000;
      n += 200;
    }
  }

  cout << n << endl;
  return 0;
}