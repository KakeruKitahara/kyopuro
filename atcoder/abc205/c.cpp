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

  ll a, b, c;
  cin >> a >> b >> c;
  if (abs(a) == abs(b))
  {
    if (a < 0 && b < 0 && c % 2 == 1)
    {
      cout << "=" << endl;
      return 0;
    }
    else if (a < 0 && c % 2 == 1)
    {
      cout << "<" << endl;
      return 0;
    }
    else if (b < 0 && c % 2 == 1)
    {
      cout << ">" << endl;
      return 0;
    }
    cout << "=" << endl;
    return 0;
  }
  else if (abs(a) < abs(b))
  {
    if (a < 0 && b < 0 && c % 2 == 1)
    {
      cout << ">" << endl;
      return 0;
    }
    else if (a < 0 && c % 2 == 1)
    {
      cout << "<" << endl;
      return 0;
    }
    else if (b < 0 && c % 2 == 1)
    {
      cout << ">" << endl;
      return 0;
    }
    cout << "<" << endl;
  }
  else
  {
    if (a < 0 && b < 0 && c % 2 == 1)
    {
      cout << "<" << endl;
      return 0;
    }
    else if (a < 0 && c % 2 == 1)
    {
      cout << "<" << endl;
      return 0;
    }
    else if (b < 0 && c % 2 == 1)
    {
      cout << ">" << endl;
      return 0;
    }
    cout << ">" << endl;
  }
  return 0;
}