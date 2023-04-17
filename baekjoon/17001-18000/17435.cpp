#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;




int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll m;
  ll f[20][200200];

  cin >> m;
  for(ll i = 1; i <= m; i++) {
    cin >> f[0][i];
  }
  for(ll k = 1; k < 20; k++) {
    for(ll i = 1; i <= m; i++) {
      f[k][i] = f[k-1][f[k-1][i]];
    }
  }

  ll Q, n, x;
  cin >> Q;
  for(ll i = 0; i < Q; i++) {
    cin >> n >> x;
    ll k = 19;
    while(k > 0) {
      if(n < (1 << k)) {
        k--;
        continue;
      } else {
        n -= (1 << k);
        x = f[k][x];
        k--;
      }
    }
    if(n == 1) {
      cout << f[0][x] << '\n';
      // cout << "Answer: " << f[0][x] << '\n';  
    } else {
      cout << x << '\n';
      // cout << "Answer: " << x << '\n';
    }
  }

  return 0;
}