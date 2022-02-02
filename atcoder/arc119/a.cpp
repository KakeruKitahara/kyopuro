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

int main()
{
  ll n;
  cin >> n;
  ll a, c;
  ll b2 = 1;
  ll mins = 1e18;
  REP(b, 61)
  {
    a = n / b2;
    c = n % b2;
    mins = min(a + b + c, mins);
    b2 *= 2;
  }
  cout << mins << endl;
  return 0;
}