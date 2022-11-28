#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, m, k, ans;
ll d_old, d_new;
bool is_valid;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m >> k;
  d_old = abs(n - m);
  for(ll i = n * m - 1; i >= 1; i--) {
    is_valid = false;
    for(ll j = 1; j * j <= i; j++) {
      if(i % j == 0) {
        d_new = abs(j - (i / j));
        if(abs(d_old - d_new) <= k) {
          is_valid = true;
          break;
        }
      }
    }
    if(is_valid) {
      if(i - 1 <= d_old + k) {
        ll next = max(d_old - k + 1, 1ll);
        ans += i - next + 1;
        i = next;
      } else {
        ans++;
      }
    } else {
      break;
    }
  }
  cout << ans << '\n';

  return 0;
}
