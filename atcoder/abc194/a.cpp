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
  int a, c, b;
  cin >> c >> b;
  a = b + c;

  if(15 <= a && 8 <= b){
    cout << "1" << endl;
  }
  else if (10 <= a && 3 <= b)
  {
    cout << "2" << endl;
  }
  else if (3 <= a)
  {
    cout << "3" << endl;
  }
  else{
    cout << "4" << endl;
  }
  return 0;
}