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

void f(S s, int n, int m)
{
  S k = to_string(n);
  if (n == 10)
    k = "a";
  else if (n == 11)
    k = "b";
  else if (n == 12)
    k = "c";
  else if (n == 13)
    k = "d";
  else if (n == 14)
    k = "e";
  else if (n == 15)
    k = "f";
  else if (n == 16)
    k = "g";
  s = s + k + s;
  if (n == m)
  {
    REP(i, s.size())
    {
      if (s[i] == 'a')
        cout << 10 << " ";
      else if (s[i] == 'b')
        cout << 11 << " ";
      else if (s[i] == 'c')
        cout << 12 << " ";
      else if (s[i] == 'd')
        cout << 13 << " ";
      else if (s[i] == 'e')
        cout << 14 << " ";
      else if (s[i] == 'f')
        cout << 15 << " ";
      else if (s[i] == 'g')
        cout << 16 << " ";
      else
        cout << s[i] << " ";
    }
    cout << endl;
    exit(0);
  }
  else
  {
    f(s, n + 1, m);
  }
}

int main()
{
  int n;
  cin >> n;
  S a;
  f(a, 1, n);

  return 0;
}