#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt, n;

void init() {
  cin >> n;
}

void solve() {
  ll q = n / 26;
  ll i = 0;
  for(ll k = 1; k <= q; k++) {
    if(k * (k + 1) / 2 <= q) {
      i = k;
    } else {
      break;
    }
  }

  if(n % 26 == 0 && i * (i + 1) / 2 == q) {
    cout << "Z\n";
    return;
  }

  if(i > 0) {
    n -= (i * (i + 1) / 2) * 26;
  }

  n = n / (i + 1) + (n % (i + 1) ? 1 : 0);
  cout << char('A' + n - 1) << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> tt;
  for(ll i = 1; i <= tt; i++) {
    cout << "Case #" << i << ": ";
    init();
    solve();
  }
  return 0;
}