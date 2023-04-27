#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, answer;
vector<ll> p, q, inv_p, inv_q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  p.resize(n + 1);
  q.resize(n + 1);
  inv_p.resize(n + 1);
  inv_q.resize(n + 1);
  for(ll i = 0; i < n; i++) {
    cin >> p[i];
    inv_p[p[i]] = i;
  }

  for(ll i = 0; i < n; i++) {
    cin >> q[i];
    inv_q[q[i]] = i;
  }

  // MEX = 1;
  ll l = min(inv_p[1], inv_q[1]);
  ll r = max(inv_p[1], inv_q[1]);
  answer += l * (l + 1) / 2;
  answer += (r - l - 1) * (r - l) / 2;
  answer += (n - r - 1) * (n - r) / 2;

  for(ll i = 2; i <= n; i++) {
    if((l <= inv_p[i] && inv_p[i] <= r) || (l <= inv_q[i] && inv_q[i] <= r)) {
      l = min(l, min(inv_p[i], inv_q[i]));
      r = max(r, max(inv_p[i], inv_q[i]));
    } else {
      if(max(inv_p[i], inv_q[i]) < l) {
        // 둘 다 왼쪽에
        answer += (l - max(inv_p[i], inv_q[i])) * (n - r);
      } else if(r < min(inv_p[i], inv_q[i])) {
        // 둘 다 오른쪽에
        answer += (min(inv_p[i], inv_q[i]) - r) * (l + 1);
      } else {
        // 양쪽에
        answer += (l - min(inv_p[i], inv_q[i])) * (max(inv_p[i], inv_q[i]) - r);
      }
      l = min(l, min(inv_p[i], inv_q[i]));
      r = max(r, max(inv_p[i], inv_q[i]));
    }
  }
  
  // MEX = N + 1
  answer++;
  cout << answer << '\n';
  
  return 0;
}