#include <bits/stdc++.h>
#define INF 999999999999
#define MAXN 550
typedef long long ll;
using namespace std;

ll n, m, capacity[MAXN][MAXN], flow[MAXN][MAXN], source, sink, visited[MAXN], max_flow;
vector<ll> e[MAXN];

void network_flow() {
  max_flow = 0;
  while (true) {
    fill(visited, visited + MAXN, -1);
    queue<ll> q;
    visited[source] = source;
    q.push(source);
    while (!q.empty()) {
      ll now = q.front();
      q.pop();
      for (ll next : e[now]) {
        if (visited[next] == -1 && capacity[now][next] - flow[now][next] > 0) {
          visited[next] = now;
          q.push(next);
          if (next == sink)
            break;
        }
      }
    }
    if (visited[sink] == -1)
      break;
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

  cin >> n >> m;

  for (ll i = 0; i < m; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    e[a].push_back(b);
    e[b].push_back(a);
    capacity[a][b] += c;
    capacity[b][a] += c;
  }

  cin >> source >> sink;

  network_flow();

  cout << max_flow << '\n';

  return 0;
}