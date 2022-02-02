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

int main()
{
  int t;
  cin >> t;
  ll n[t];
  REP(i, t)
  {
    cin >> n[i];
  }
  REP(i, t){
    if(n[i] % 4 == 0){
      cout << "Even\n";
    }
    else if (n[i] % 2 == 1){
      cout << "Odd\n";
    }
    else{
      cout << "Same\n";
    }
  }
  return 0;
}