#include <bits/stdc++.h>
#define INF 999999999999
#define MAX 1010
typedef long long ll;
using namespace std;

ll n, m, k, c[MAX][MAX], f[MAX][MAX], visited[MAX], source, sink, dist[MAX], in_queue[MAX], cost[MAX][MAX];
vector<ll> e[MAX];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  for(ll i = 0; i < n; i++) {
    cin >> k;
    e[i].resize(k);
    for(ll j = 0; j < k; j++) {
      cin >> e[i][j];
      e[i][j] += n - 1;
      cin >> cost[i][e[i][j]];
    }
  }

  for(ll i = 0; i < n; i++) {
    for(auto work: e[i]) {
      e[work].push_back(i);
      cost[work][i] = -cost[i][work];
      c[i][work] = 1;
    }
  }

  source = MAX - 1;
  sink = MAX - 2;
  for(ll i = 0; i < n; i++) {
    e[source].push_back(i);
    e[i].push_back(source);
    c[source][i] = 1;
  }

  for(ll i = n; i < n + m; i++) {
    e[i].push_back(sink);
    e[sink].push_back(i);
    c[i][sink] = 1;
  }

  ll total_flow = 0, total_cost = 0;
  while(true) {
    fill(visited, visited + MAX, -1);
    fill(dist, dist + MAX, INF);
    fill(in_queue, in_queue + MAX, false);
    queue<ll> q;
    dist[source] = 0;
    in_queue[source] = true;
    q.push(source);
    while(q.size()) {
      ll now = q.front();
      q.pop();
      in_queue[now] = false;
      for(ll next: e[now]) {
        if(dist[next] > dist[now] + cost[now][next] && c[now][next] - f[now][next] > 0) {
          dist[next] = dist[now] + cost[now][next];
          visited[next] = now;
          if(!in_queue[next]) {
            in_queue[next] = true;
            q.push(next);
          }
        }
      }
    }
    if(dist[sink] == INF) break;
    ll partial_flow = INF;
    ll now = sink;
    while(now != source) {
      ll next = visited[now];
      partial_flow = min(partial_flow, c[next][now] - f[next][now]);
      now = next;
    }

    now = sink;
    while(now != source) {
      ll next = visited[now];
      f[next][now] += partial_flow;
      f[now][next] -= partial_flow;
      total_cost += partial_flow * cost[next][now];
      now = next;
    }

    total_flow += partial_flow;
  }

    cout << total_flow << '\n';
    cout << total_cost << '\n';
  
  return 0;
}