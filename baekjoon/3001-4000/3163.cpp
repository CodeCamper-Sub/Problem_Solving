#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, l, k;
vector<pair<ll, ll>> ants;
vector<pair<ll, ll>> time_to_drop;

void init() {
  cin >> n >> l >> k;
  ants.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> ants[i].first >> ants[i].second;
  }
  time_to_drop.clear();
}

ll answer(ll id) {
  queue<ll> q;
  if(id > 0) {
    // 오른쪽 진행
    for(ll i = 0; i < n; i++) {
      if(q.size() == 0 && ants[i].second != id) continue;
      q.push(ants[i].second);
      if(ants[i].second < 0) {
        q.pop();
      }
    }
  } else{
    // 왼쪽 진행
    for(ll i = n - 1; i >= 0; i--) {
      if(q.size() == 0 && ants[i].second != id) continue;
      q.push(ants[i].second);
      if(ants[i].second > 0) {
        q.pop();
      }
    }
  }
  return q.front();
}

void solve() {
  for(auto [location, id]: ants) {
    if(id > 0) {
      // 오른쪽으로 진행
      time_to_drop.push_back({l - location, id});
    } else {
      time_to_drop.push_back({location, id});
    }
  }
  sort(time_to_drop.begin(), time_to_drop.end());
  if(k - 2 >= 0 && time_to_drop[k - 2].first == time_to_drop[k - 1].first) {
    cout << max(answer(time_to_drop[k - 2].second), answer(time_to_drop[k - 1].second)) << '\n';
  } else if(k < n && time_to_drop[k - 1].first == time_to_drop[k].first) {
    cout << min(answer(time_to_drop[k - 1].second), answer(time_to_drop[k].second)) << '\n';
  } else {
    cout << answer(time_to_drop[k - 1].second) << '\n';
  }
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