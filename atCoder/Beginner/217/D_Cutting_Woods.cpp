#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll l, q, c, x;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> l >> q;
  set<ll> cut;
  cut.insert(0);
  cut.insert(l);
  while(q--) {
    cin >> c >> x;
    if(c == 1) {
      cut.insert(x);
    } else if(c == 2) {
      auto upper = cut.lower_bound(x);
      auto lower = upper;
      lower--;
      cout << (*upper - *lower) << '\n';
    }
  }
  
  return 0;
}