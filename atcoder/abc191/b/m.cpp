#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= n; i--)
#define REPR2(i, a, n) for (int i = a; 0 <= n; i--)
using V = vector<int>;
using P = pair<int, int>;
using ll = long long;
using namespace std;

int main()
{
  int n, j = 0;
  string x;
  cin >> n >> x;
  vector<string> a(n);
  vector<int> in(n, -1);
  REP(i, n)
  cin >> a[i];

  REP(i, n)
  {
    if (a[i] == x)
    {
      in[j] = i;
      j++;
    }
  }

j = 0;
  REP(i, n)
  {
    if (in[j] != i){
      cout << a[i] << " ";
    }
    else
      j++;
  }

  return 0;
}