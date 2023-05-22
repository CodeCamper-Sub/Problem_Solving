#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;
vector<ll> a, b;
deque<pair<ll, ll>> q;

void init() {
  cin >> n;
  a.resize(n); b.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(ll i = 0; i < n; i++){ 
    cin >> b[i];
  }
  while(q.size()) q.pop_back();
}

void solve() {
  ll answer = 0;
  for(ll i = 0; i < n; i++) {
    q.push_back({a[i], b[i]});
  }
  while(q.size() > 1) {
    if(q.front().second <= q.back().second) {
      auto [a, b] = q.front(); q.pop_front();
      answer += a;
      q.front().first += b;
    } else {
      auto [a, b] = q.back(); q.pop_back();
      answer += a;
      q.back().first += b;
    }
  }
  answer += q.back().first;
  q.pop_back();

  cout << answer << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll tt;
  cin >> tt;
  for(ll T = 1; T <= tt; T++) {
    init();
    solve();
  }
  return 0;
}