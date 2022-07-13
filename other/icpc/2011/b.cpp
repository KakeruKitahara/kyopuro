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

void solve(S s)
{
  stack<char> c;
  c.push('a');
  REP(i, s.size())
  {
    if (s[i] == '(' || s[i] == '[')
    {
      c.push(s[i]);
    }
    else if (s[i] == ')' || s[i] == ']')
    {
      char z = c.top();
      if (!((s[i] == ')' && z == '(') || (s[i] == ']' && z == '[')))
      {
        cout << "no" << endl;
        return;
      }

      if (z == 'a')
      {
        cout << "no" << endl;
        return;
      }
      c.pop();
    }
  }

  if (c.size() == 1)
  {
    cout << "yes" << endl;
  }
  else
  {
    cout << "no" << endl;
  }
}

int main()
{
  while (1)
  {
    S a;
    getline(cin, a);
    if (a == ".")
    {
      break;
    }
    solve(a);
  }

  return 0;
}

