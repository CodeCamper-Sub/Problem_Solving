#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, m;
min_heap<pair<ll, ll>> q;
vector<ll> k;
vector<ll> visited;
ll r;
vector<vector<pair<ll, ll>>> e;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  k.resize(n);
  e.resize(n);

  for(ll& k: k) cin >> k;
  cin >> r;
  while(r--) {
    ll a, b, d;
    cin >> a >> b >> d;
    a--; b--;
    e[a].push_back({b, d});
  }

  visited.assign(n, false);
  ll mini = *min_element(k.begin(), k.end());
  for(ll i = 0; i < n; i++) {
    q.push({k[i], i});
  }

  ll answer = 0;
  ll cnt = 0;
  while(q.size()) {
    auto [cost, now] = q.top();
    q.pop();
    if(visited[now]) continue;
    visited[now] = true;
    answer = max(answer, cost);
    cnt++;
    if(cnt >= m) break;
    
    for(auto [next, d]: e[now]) {
      k[next] -= d;
      if(visited[next]) continue;
      q.push({k[next], next});
    }
  }

  cout << answer << '\n';
  
  return 0;
}