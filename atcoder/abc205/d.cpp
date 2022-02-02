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
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  vector<pair<ll, int>> k(q);
  REP(i, n)
  {
    cin >> a[i];
  }
  REP(i, q)
  {
    cin >> k[i].first;
    k[i].second = i;
  }

  vector<ll> ans(q);

  sort(k.begin(), k.end());

  int j = 0;
  REP(i, q)
  {
    ll tmp = k[i].first + j;
    while (a[j] <= tmp)
    {

      if (j == n)
      {
        break;
      }
      tmp++;
      j++;
    }
    ans[k[i].second] = j + k[i].first;
  }

  REP(i, q)
  {
    cout << ans[i] << endl;
  }
  return 0;
}

/*
4 3
1 2 4 5
1 2 1
*/