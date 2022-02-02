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
using namespace std;

int main()
{
  ll n;
  cin >> n;

  ll a = 2;
  set<ll> ans;
  while (a * a <= n) // aはint型なのでa * aもint型になるので注意.
  {
    ll tmp = a * a;
    while (tmp <= n)
    {
      ans.insert(tmp);
      tmp *= a;
    }
    a++;
  }

  cout << n - ans.size() << endl;
  return 0;
}