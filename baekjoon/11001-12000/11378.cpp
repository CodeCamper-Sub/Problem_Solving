#include <bits/stdc++.h>
#define INF 999999999999
#define MAX 2020
typedef long long ll;
using namespace std;

ll n, m, k, source, transit, sink, capacity[MAX][MAX], flow[MAX][MAX], visited[MAX], answer;
vector<ll> e[MAX];

void network_flow() {
  while(true) {
    fill(visited, visited + MAX, -1);
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
    answer += min_flow;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m >> k;
  for(ll i = 0; i < n; i++) {
    ll t;
    cin >> t;
    while(t--) {
      ll x;
      cin >> x;
      x += n - 1;
      e[i].push_back(x);
      e[x].push_back(i);
      capacity[i][x] += 1;
    }
  }

  source = n + m;
  transit = n + m + 1;
  sink = n + m + 2;
  
  e[source].push_back(transit);
  e[transit].push_back(source);
  capacity[source][transit] = k;

  for(ll i = 0; i < n; i++) {
    e[transit].push_back(i);
    e[i].push_back(transit);
    capacity[transit][i] = k;

    e[source].push_back(i);
    e[i].push_back(source);
    capacity[source][i] = 1;
  }

  for(ll i = 0; i < m; i++) {
    e[n + i].push_back(sink);
    e[sink].push_back(n + i);
    capacity[n + i][sink] = 1;
  }
  
  network_flow();

  cout << answer << '\n';
  
  return 0;
}