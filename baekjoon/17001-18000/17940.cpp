#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, source, sink;
vector<ll> col;
vector<vector<pair<ll, ll>>> e;
vector<vector<ll>> visited;
vector<ll> min_trans;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> sink;

  source = 0;
  col.resize(n);
  e.resize(n);
  visited.assign(n, vector<ll>(n, INF));
  min_trans.assign(n, INF);
  for(ll i = 0; i < n; i++) cin >> col[i];
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < n; j++) {
      ll c;
      cin >> c;
      if(c) {
        e[i].push_back({j, c});
      }
    }
  }


  min_heap<tuple<ll, ll, ll>> q; // {환승 횟수, 코스트, 현재 위치}
  q.push({0, 0, source});
  visited[0][0] = 0;
  min_trans[0] = 0;
  while(q.size()) {
    auto [trans, dist, now] = q.top();
    q.pop();
    if(dist > visited[trans][now]) continue;
    for(auto [next, cost]: e[now]) {
      ll ntrans = trans;
      if(col[now] != col[next]) ntrans++;
      if(ntrans > min_trans[next]) continue;
      if(visited[ntrans][next] <= dist + cost) continue;
      q.push({ntrans, dist + cost, next});
      visited[ntrans][next] = dist + cost;
      min_trans[next] = min(min_trans[next], ntrans);
    }
  }

  for(ll i = 0; i < n; i++) {
    if(visited[i][sink] != INF) {
      cout << i << ' ' << visited[i][sink] << '\n';
      return 0;
    }
  }


  
  return 0;
}