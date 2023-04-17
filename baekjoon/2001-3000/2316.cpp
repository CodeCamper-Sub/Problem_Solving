#include <bits/stdc++.h>
#define INF 999999999999
#define MAXN 440
#define MAXP 10100
typedef long long ll;
using namespace std;

ll n, p, capacity[2 * MAXN][2 * MAXN], flow[2 * MAXN][2 * MAXN], source, sink, visited[2 * MAXN], max_flow;
vector<ll> e[2 * MAXN];

void network_flow() {
  while(true) {
    fill(visited, visited + 2 * MAXN, -1);
    queue<ll> q;
    visited[source] = source;
    q.push(source);
    while(!q.empty()) {
      ll now = q.front(); q.pop();
      for(ll next: e[now]) {
        if(visited[next] == -1 && capacity[now][next] - flow[now][next] > 0) {
          visited[next] = now;
          q.push(next);
          if(next == sink) break;
        }
      }
    }
    if(visited[sink] == -1) break;
    ll now = sink;
    ll min_flow = INF;
    while(now != source) {
      ll next = visited[now];
      min_flow = min(min_flow, capacity[next][now] - flow[next][now]);
      now = next;
    }
    now = sink;
    while(now != source) {
      ll next = visited[now];
      flow[next][now] += min_flow;
      flow[now][next] -= min_flow;
      now = next;
    }
    max_flow += min_flow;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> p;
  for(ll i = 0; i < p; i++) {
    ll u, v;
    cin >> u >> v;
    if(u < v) swap(u, v);
    if(v == 2) {
      e[u].push_back(v);
      e[v].push_back(u);
      capacity[u][v] += 1;
    } else {
      e[u].push_back(v + n);
      e[v + n].push_back(u);
      capacity[u][v + n] += 1;

      e[v].push_back(n + u);
      e[n + u].push_back(v);
      capacity[v][n + u] += 1;
    }
  }

  for(ll i = 3; i <= n; i++) {
    e[i + n].push_back(i);
    e[i].push_back(i + n);
    capacity[i + n][i] = 1;
  }

  source = 1;
  sink = 2;

  network_flow();

  cout << max_flow << '\n';

  return 0;
}