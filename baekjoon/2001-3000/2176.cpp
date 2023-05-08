#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m;
vector<vector<pair<ll, ll>>> e;
vector<ll> dist, inQ, visited;
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
priority_queue<pair<ll, ll>> q2;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  e.resize(n + 1);
  for(ll i = 0; i < m; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    e[a].push_back({b, c});
    e[b].push_back({a, c});
  }

  dist.assign(n + 1, INF);
  dist[2] = 0;
  q.push({dist[2], 2});

  while(q.size()) {
    auto [d, now] = q.top();
    q.pop();
    if(dist[now] < d) continue;
    for(auto [next, cost]: e[now]) {
      if(dist[next] > dist[now] + cost) {
        dist[next] = dist[now] + cost;
        q.push({dist[next], next});
      }
    }
  }

  inQ.assign(n + 1, false);
  visited.assign(n + 1, 0);
  visited[1] = 1;
  q2.push({dist[1], 1});
  while(q2.size()) {
    auto [_, now] = q2.top();
    q2.pop();
    inQ[now] = false;
    for(auto [next, _]: e[now]) {
      if(dist[next] < dist[now]) {
        visited[next] += visited[now];
        if(!inQ[next]) {
          inQ[next] = true;
          q2.push({dist[next], next});
        }
      }
    }
  }

  cout << visited[2] << '\n';
  
  return 0;
}