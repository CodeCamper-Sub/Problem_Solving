#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll m, k;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> m;
  k = 5;
  while(true) {
    ll now = k;
    while(now % 5 == 0) {
      now /= 5;
      m--;
    }
    if(m == 0) {
      cout << k << '\n';
      return 0;
    } else if(m < 0) {
      cout << -1 << '\n';
      return 0;
    }

    k += 5;
  }
  
  return 0;
}