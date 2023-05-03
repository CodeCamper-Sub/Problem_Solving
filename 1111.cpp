#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, a, b;
vector<ll> x;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  x.resize(n);

  for(ll i = 0; i < n; i++) cin >> x[i];
  if(n == 1) {
    cout << "A\n";
    return 0;
  } else if(n == 2) {
    if(x[0] == x[1]) {
      cout << x[0] << '\n';
    } else {
      cout << "A\n";
    }
    return 0;
  }
  a = b = INF;
  for(ll i = 0; i < n - 2; i++) {
    if(x[i] == x[i + 1]) continue;
    if((x[i + 1] - x[i + 2]) % (x[i] - x[i + 1])) {
      cout << "B\n";
      return 0;
    }
    a = (x[i + 1] - x[i + 2]) / (x[i] - x[i + 1]);
    b = x[i + 1] - x[i] * a;
    break;
  }
  
  if(a == INF) {
    if(x[0] == x.back()) {
      cout << x[0] << '\n';
      return 0;
    } else {
      cout << "B\n";
      return 0;
    }
  }

  for(ll i = 0; i < n - 1; i++) {
    if(x[i] * a + b != x[i + 1]) {
      cout << "B\n";
      return 0;
    }
  }
  cout << x.back() * a + b << '\n';

  return 0;
}