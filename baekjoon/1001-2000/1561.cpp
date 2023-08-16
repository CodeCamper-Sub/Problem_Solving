#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, m;
vector<ll> t;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  if(n <= m) {
    cout << n << '\n';
    return 0;
  }
  t.resize(m);
  for(ll& t: t) cin >> t;
  ll maxi = *max_element(t.begin(), t.end());
  ll left = 0;
  ll right = maxi * n;
  while(left <= right) {
    ll mid = (left + right) / 2;
    ll cnt = 0;
    for(ll i = 0; i < m; i++) {
      cnt += mid / t[i] + (mid % t[i] ? 1 : 0);
    }

    if(cnt + m < n) {
      left = mid + 1;
    } else if(cnt >= n) {
      right = mid - 1;
    } else {
      min_heap<pair<ll, ll>> q;
      for(ll i = 0; i < m; i++) {
        q.push({(t[i] - mid % t[i]) % t[i], i});
      }
      ll k = n - cnt - 1;
      while(k--) {
        auto [time, idx] = q.top(); q.pop();
        q.push({time + t[idx], idx});
      }
      cout << q.top().second + 1 << '\n';
      return 0;
    }
  }

  assert(false);
  
  return 0;
}