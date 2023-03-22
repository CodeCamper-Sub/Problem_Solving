#include <bits/stdc++.h>
#define INF 999999999999
#define MAX 550
typedef long long ll;
using namespace std;

ll n, m, a, b, c, visited[MAX], dist[MAX], in_queue[MAX];
vector<pair<ll, ll>> e[MAX];
queue<ll> q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  for(ll i = 0; i < m; i++) {
    cin >> a >> b >> c;
    e[a].push_back({b, c});
  }

  fill(dist, dist + MAX, INF);

  dist[1] = 0;
  visited[1]++;
  in_queue[1] = true;
  q.push(1);
  bool has_negative_cycle = false;
  while(q.size()) {
    ll now = q.front();
    q.pop();
    in_queue[now] = false;
    for(auto [next, cost]: e[now]) {
      if(dist[next] > dist[now] + cost) {
        dist[next] = dist[now] + cost;
        if(!in_queue[next]) {
          if(++visited[next] >= n) {
            has_negative_cycle = true;
          }
          in_queue[next] = true;
          q.push(next);
        }
      }
    }
    if(has_negative_cycle) break;
  }

  if(has_negative_cycle) {
    cout << -1 << '\n';
  } else {
    for(ll i = 2; i <= n; i++) {
      if(dist[i] != INF) {
        cout << dist[i] << '\n';
      } else {
        cout << -1 << '\n';
      }
    }
  }
  
  return 0;
}