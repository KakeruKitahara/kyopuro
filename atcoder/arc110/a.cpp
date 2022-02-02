#include <bits/stdc++.h>
using namespace std;

long long int double_gcd(long long int a, int b) // 数値的にlong long型のことも考慮する.
{
  long long int k = a;
  int m = b;
  int r;
  while (k % m)
  {
    r = k % m;
    k = m;
    m = r;
  }
  return m;
}

long long int double_lcm(long long int a, int b)
{
  return a * b / double_gcd(a, b);
}

int main()
{
  int n;
  scanf("%d", &n);
  long long sum = 2;
  for (int i = 3; i <= n; i++)
  {
    sum = double_lcm(sum, i);
  }
  printf("%lld\n", sum + 1);
  return 0;
}

/*
#include <bits/stdc++.h>
#define rep(x, y) for (int x = 0; x < y; x++)
#define ll long long
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<vector<int>> table(31, vector<int>(31));
  for (int i = 2; i <= n; i++)
  {
    int t = i;
    for (int j = 2; j <= i;)
    {
      if (t % j == 0)
      {
        table[i][j]++;
        t /= j;
      }
      else
      {
        j++;
      }
    }
    if (t == i)
      table[i][t]++;
  }
  ll sum = 1;
  for (int i = 2; i <= n; i++)
  {
    int nmax = 0;
    for (int j = 2; j <= n; j++)
    {
      nmax = max(table[j][i], nmax);
    }
    sum *= pow(i, nmax);
  }
  cout << sum + 1 << endl;
}
*/