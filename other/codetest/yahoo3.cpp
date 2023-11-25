#include <bits/stdc++.h>
using namespace std;

/* macro */
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
using V = vector<int>;
using VV = vector<vector<int>>;
using VVV = vector<vector<vector<int>>>;
using Vl = vector<long long>;
using VVl = vector<vector<long long>>;
using VVVl = vector<vector<vector<long long>>>;
using P = pair<int, int>;
using Pl = pair<long long, long long>;
using VP = vector<pair<int, int>>;
using VVP = vector<vector<pair<int, int>>>;
using S = string;
using VS = vector<string>;
using VVS = vector<vector<string>>;
using ll = long long;
constexpr int IINF = 1000000000 + 8;
constexpr long long LINF = 1000000000000000000LL + 8;

unsigned long long factorial(unsigned long long n)
{
  if (n == 0 || n == 1)
  {
    return 1;
  }
  else
  {
    return n * factorial(n - 1);
  }
}

unsigned long long combination(unsigned long long n, unsigned long long r)
{
  return factorial(n) / (factorial(r) * factorial(n - r));
}

int main()
{
  string input;
  ll n, m;
  getline(cin, input);
  if (input.empty())
  {
    exit(100);
  }

  istringstream stream(input);
  if (!(stream >> n))
  {
    exit(100);
  }
  if (!(stream >> m))
  {
    exit(100);
  }

  if ((n * m) % 2 == 0)
  {
    vector<vector<ll>> cb(150, vector<ll>(150, 0));
    for (ll j = 0; j < 150; j++)
      cb[j][0] = 1;
    for (ll i = 1; i < 150; i++)
    {
      for (ll j = 1; j < 150; j++)
      {
        cb[i][j] = cb[i - 1][j - 1] + cb[i - 1][j];
      }
    }

    cout << setw(9) << setfill('0') << cb[n * m][(n * m) / 2]  % 1000000000 << endl;
  }
  else
  {
    cout << setw(9) << setfill('0') << 0 << endl;
  }

  return 0;
}