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

int main()
{
  string n;
  int k;
  cin >> n >> k;

  REP(i, k)
  {
    string tn = n, tn2 = n;
    sort(tn.rbegin(), tn.rend());
    sort(tn2.begin(), tn2.end());
    int num = atoi(tn.c_str());
    int num2 = atoi(tn2.c_str());
    n = std::to_string(num - num2);
  }

  cout << n;
  return 0;
}
