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

int main()
{
  int n, a, b;
  cin >> n >> a >> b;
  int f = 1, s;
  REP(i, n * a)
  {
    REP(j, n * b)
    {

      if (j % b == 0)
      {
        f++;
        f %= 2;
      }

      if (j == 0)
      {
        if (i % a == 0)
        {
          f = (s + 1) % 2;
        }
        else
        {
          f = s;
        }
        s = f;
      }

      if(i == 0 && j == 0){
        s = 1;
        f = 1;
      }

      if (f == 1)
      {
        cout << ".";
      }
      else
      {
        cout << "#";
      }
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}