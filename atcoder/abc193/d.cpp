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

int ctoi(const char c)
{
  switch (c)
  {
  case '0':
    return 0;
  case '1':
    return 1;
  case '2':
    return 2;
  case '3':
    return 3;
  case '4':
    return 4;
  case '5':
    return 5;
  case '6':
    return 6;
  case '7':
    return 7;
  case '8':
    return 8;
  case '9':
    return 9;
  default:
    return -1;
  }
}

int powi(int a, int n)
{
  int res = 1;
  REP(i, n)
  {
    res *= a;
  }
  return res;
}

int main()
{
  S s, t;
  int k;
  cin >> k >> s >> t;

  V s2(9, 0), t2(9, 0);
  vector<ll> card(9, k);
  REP(i, 4)
  {
    int tmp = ctoi(s[i]);
    card[tmp - 1]--;
    s2[tmp - 1]++;
    tmp = ctoi(t[i]);
    card[tmp - 1]--;
    t2[tmp - 1]++;
  }

  int valueS = 0, valueT = 0;

  REP(i, 9)
  {
    valueS += (i + 1) * powi(10, s2[i]);
    valueT += (i + 1) * powi(10, t2[i]);
  }

  ll ans = 0;

  REP(i, 9)
  {
    int tmpS, tmpT;
    REP(j, 9)
    {
      tmpS = valueS;
      tmpT = valueT;
      if (i != j && 0 <= card[i] - 1 && 0 <= card[j] - 1)
      {
        tmpS += (i + 1) * pow(10, s2[i] + 1) - (i + 1) * pow(10, s2[i]);
        tmpT += (j + 1) * pow(10, t2[j] + 1) - (j + 1) * pow(10, t2[j]);

        if (tmpS > tmpT)
        {
          ans += card[i] * card[j];
        }
      }
      if (i == j && 0 <= card[i] - 2)
      {
        tmpS += (i + 1) * pow(10, s2[i] + 1) - (i + 1) * pow(10, s2[i]);
        tmpT += (j + 1) * pow(10, t2[j] + 1) - (j + 1) * pow(10, t2[j]);

        if (tmpS > tmpT)
        {
          ans += card[i] * (card[i] - 1);
        }
      }
    }
  }

  ll sum = (9 * (ll)k - 8) * (9 * k - 9);
  cout << (double)ans / sum << endl;
  return 0;
}
