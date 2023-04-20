#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll solution(int a, int b, vector<int> g, vector<int> s, vector<int> w,
                   vector<int> t) {
  ll n = g.size();
  ll right = ((ll(1e9) * 2 - 1) * 2 + 1) * ll(1e5);
  ll left = 0;
  vector<ll> tw(n), gg(n), ss(n);
  while(left <= right) {
    ll mid = (left + right) / 2;
    ll aa = a;
    ll bb = b;
    for(ll i = 0; i < n; i++) {
      if((mid / t[i]) % 2) {
        tw[i] = ((mid / t[i]) / 2 + 1) * w[i];
      } else {
        tw[i] = (mid / t[i]) / 2 * w[i];
      }
      gg[i] = 0;
      ss[i] = 0;
    }
    for(ll i = 0; i < n; i++) {
      ll delta = min(tw[i], ll(g[i]));
      aa -= delta;
      gg[i] += delta;
      tw[i] -= delta;
    }
    for(ll i = 0; i < n; i++) {
      ll delta = min(ll(s[i]), tw[i]);
      bb -= delta;
      ss[i] += delta;
      if(aa <= 0 && bb > 0) {
        // -a, gg[i], s[i] - ss[i] 중 최솟값 만큼 가능
        delta = min(min(-aa, gg[i]), s[i] - ss[i]);
        aa += delta;
        bb -= delta;
        gg[i] -= delta;
        ss[i] += delta;
      }
    }
    if(aa <= 0 && bb <= 0) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return left;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n, a, b;
  cin >> n >> a >> b;
  vector<int> g, s, w, t;
  g.resize(n);
  s.resize(n);
  w.resize(n);
  t.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> g[i];
  }
  for(ll i = 0; i < n; i++) {
    cin >> s[i];
  }
  for(ll i = 0; i < n; i++) {
    cin >> w[i];
  }
  for(ll i = 0; i < n; i++) {
    cin >> t[i];
  }

  cout << solution(a, b, g, s, w, t) << '\n';

  return 0;
}