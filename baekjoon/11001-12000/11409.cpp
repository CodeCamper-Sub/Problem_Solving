#include <bits/stdc++.h>
#define INF 999999999999
#define MAX 1000
typedef long long ll;
using namespace std;

ll n, m, k, capacity[MAX][MAX], flow[MAX][MAX], cost[MAX][MAX], source, sink, visited[MAX], dist[MAX], inQ[MAX];
vector<ll> e[MAX];

void make_edge(ll now, ll next, ll _capacity, ll _cost) {
  e[now].push_back(next);
  e[next].push_back(now);
  capacity[now][next] += _capacity;
  cost[now][next] = _cost;
  cost[next][now] = -_cost;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  for(ll i = 1; i <= n; i++) {
    cin >> k;
    while(k--) {
      ll w, c;
      cin >> w >> c;
      make_edge(i, n + w, 1, -c);
    }
  }

  source = MAX - 1;
  sink = MAX - 2;

  for(ll i = 1; i <= n; i++) {
    make_edge(source, i, 1, 0);
  }

  for(ll i = 1; i <= m; i++) {
    make_edge(n + i, sink, 1, 0);
  }

  ll total_cost = 0, total_flow = 0;
  while(true) {
    fill(visited, visited + MAX, -1);
    fill(dist, dist + MAX, INF);
    fill(inQ, inQ + MAX, false);
    queue<ll> q;
    visited[source] = 0;
    dist[source] = 0;
    inQ[source] = true;
    q.push(source);
    while(q.size()) {
      ll now = q.front();
      q.pop();
      inQ[now] = false;
      for(ll next: e[now]) {
        if(dist[next] > dist[now] + cost[now][next] && capacity[now][next] - flow[now][next] > 0) {
          visited[next] = now;
          dist[next] = dist[now] + cost[now][next];
          if(!inQ[next]) {
            inQ[next] = true;
            q.push(next);
          }
        }
      }
    }
    if(visited[sink] == -1) break;
    ll min_flow = INF;
    ll now = sink;
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
      total_cost += min_flow * cost[next][now];
      now = next;
    }
    total_flow += min_flow;
  }

  cout << total_flow << '\n';
  cout << -total_cost << '\n';
  
  return 0;
}