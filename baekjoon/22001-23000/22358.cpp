#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m, k, source, sink;
vector<vector<pair<ll, ll>>> e;
vector<vector<ll>> visited;
vector<vector<bool>> inQ;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m >> k >> source >> sink;
  e.resize(n + 1);
  for(ll i = 0; i < m; i++) {
    ll a, b, t;
    cin >> a >> b >> t;
    e[a].push_back({b, t});
    e[b].push_back({a, t});
  }
  visited.assign(k + 1, vector<ll>(n + 1, -INF));
  inQ.assign(k + 1, vector<bool>(n + 1, false));
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
  q.push({0, source});
  inQ[0][source] = true;
  visited[0][source] = 0;
  while(q.size()) {
    auto [lift, now] = q.top();
    q.pop();
    inQ[0][source] = false;
    for(auto [next, dist]: e[now]) {
      if(now < next) {  // 내려가기
        if(visited[lift][next] < visited[lift][now] + dist) {
          visited[lift][next] = visited[lift][now] + dist;
          if(!inQ[lift][next]) {
            q.push({lift, next});
            inQ[lift][next] = true;
          }
        }
      } else {
        if(lift + 1 <= k && visited[lift + 1][next] < visited[lift][now]) {
          visited[lift + 1][next] = visited[lift][now];
          if(!inQ[lift + 1][next]) {
            q.push({lift + 1, next});
            inQ[lift + 1][next] = true;
          }
        }
      }
    }
  }
  ll answer = -INF;
  for(ll i = 0; i <= k; i++) answer = max(answer, visited[i][sink]);
  if(answer != -INF) {
    cout << answer << '\n';
  } else {
    cout << -1 << '\n';
  }

  
  return 0;
}