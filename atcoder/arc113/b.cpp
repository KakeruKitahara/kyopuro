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

int func(int a, int b)
{
  int tmp;
  tmp = b % 4;
  if (a == 1)
  {
    return 1;
  }
  else if (a == 2)
  {
    if (tmp == 0)
    {
      return 2;
    }
    else if (tmp == 1)
    {
      return 4;
    }
    else if (tmp == 2)
    {
      return 8;
    }
    else
    {
      return 6;
    }
  }
  else if (a == 3)
  {
    if (tmp == 0)
    {
      return 3;
    }
    else if (tmp == 1)
    {
      return 9;
    }
    else if (tmp == 2)
    {
      return 7;
    }
    else
    {
      return 1;
    }
  }
  else if (a == 4)
  {
    if (tmp == 0 || tmp == 2)
    {
      return 4;
    }
    else
    {
      return 6;
    }
  }
  else if (a == 5)
  {
    return 5;
  }
  else if (a == 6)
  {
    return 6;
  }
  else if (a == 7)
  {
    if (tmp == 0)
    {
      return 7;
    }
    else if (tmp == 1)
    {
      return 9;
    }
    else if (tmp == 2)
    {
      return 3;
    }
    else
    {
      return 1;
    }
  }
  else if (a == 8)
  {
    if (tmp == 0)
    {
      return 8;
    }
    else if (tmp == 1)
    {
      return 4;
    }
    else if (tmp == 2)
    {
      return 2;
    }
    else
    {
      return 6;
    }
  }
  else
  {
    if (tmp == 0 || tmp == 2)
    {
      return 9;
    }
    else
    {
      return 1;
    }
  }
}

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  ll sum = 0;
  REP(i, c)
  {
    sum *= b;
  }
  cout << func(a, sum);
  return 0;
}

/* WA */