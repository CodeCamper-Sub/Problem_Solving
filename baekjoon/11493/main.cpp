#include <bits/stdc++.h>
#define INF 999999999999
#define MAX 550
typedef long long ll;
using namespace std;

ll tt, n, m, source, sink, capacity[MAX][MAX], flow[MAX][MAX], cost[MAX][MAX], visited[MAX], dist[MAX], inQ[MAX];
vector<ll> e[MAX];

void make_edge(ll now, ll next, ll _capacity, ll _cost) {
  e[now].push_back(next);
  e[next].push_back(now);
  capacity[now][next] += _capacity;
  capacity[next][now] += _capacity;
  cost[now][next] = _cost;
  cost[next][now] = _cost;
}

void solve() {
  for(ll i = 0; i < m; i++) {
    ll x, y;
    cin >> x >> y;
    make_edge(x, y, INF, 1);
  }
  for(ll i = 1; i <= n; i++) {
    ll color;
    cin >> color;
    if(color) {
      make_edge(i, sink, 1, 0);
    }
  }
  for(ll i = 1; i <= n; i++) {
    ll color;
    cin >> color;
    if(color) {
      make_edge(source, i, 1, 0);
    }
  }

  ll total_cost = 0;
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
        if(flow[now][next] < 0) {
          if(dist[next] > dist[now] - cost[now][next] && capacity[now][next] - flow[now][next] > 0) {
            visited[next] = now;
            dist[next] = dist[now] - cost[now][next];
            if(!inQ[next]) {
              inQ[next] = true;
              q.push(next);
            }
          }
        } else {
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
      if(flow[next][now] < 0) {
        total_cost -= min_flow * cost[next][now];
      } else {
        total_cost += min_flow * cost[next][now];
      }
      flow[next][now] += min_flow;
      flow[now][next] -= min_flow;
      now = next;
    }
  }
  
  #ifdef DEBUG
  cout << "\nAns: ";
  #endif
  cout << total_cost << '\n';
}

void init() {
  cin >> n >> m;
  source = n + 1;
  sink = n + 2;
  for(ll i = 0; i <= n + 2; i++) {
    e[i].clear();
    for(ll j = 0; j <= n + 2; j++) {
      capacity[i][j] = 0;
      flow[i][j] = 0;
      cost[i][j] = 0;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> tt;

  while(tt--){ 
    init();
    solve();
  }

  return 0;
}