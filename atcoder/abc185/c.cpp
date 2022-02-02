#include <bits/stdc++.h>

using namespace std;

int main()
{
  int l;
  long long int sum = 1; // 2^63より, int上限に注意.
  scanf("%d", &l);
  for (int i = 0; i < 11; i++) // やってることはL-1C11をやるだけ. どこの座標に棒を入れるかを選ぶ.
  {
    sum *= (l - 1 - i);
    sum /= (i + 1);
  }

  printf("%lld", sum);
  return 0;
}