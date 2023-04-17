#include <bits/stdc++.h>
#define INF 999999999999
#define MAX 440
#define fill2d(arr, row, column, value) fill(&arr[0][0], &arr[row - 1][column], value)
typedef long long ll;
using namespace std;

ll n, p, capacity[MAX][MAX], flow[MAX][MAX], visited[MAX], answer;
vector<ll> e[MAX];

void network_flow(ll start, ll end) {
  while(true) {
    fill(visited, visited + MAX, -1);
    queue<ll> q;
    q.push(start);
    while(!q.empty()) {
      ll now = q.front(); q.pop();
      for(ll next: e[now]) {
        if(visited[next] == -1 && capacity[now][next] - flow[now][next] > 0) {
          visited[next] = now;
          q.push(next);
          if(next == end) break;
        }
      }
    }
    if(visited[end] == -1) break;
    ll now = end;
    ll min_flow = INF;
    while(now != start) {
      ll next = visited[now];
      min_flow = min(min_flow, capacity[next][now] - flow[next][now]);
      now = next;
    }
    now = end;
    while(now != start) {
      ll next = visited[now];
      flow[next][now] += min_flow;
      flow[now][next] -= min_flow;
      now = next;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> p;
  fill2d(capacity, MAX, MAX, 0);
  fill2d(flow, MAX, MAX, 0);
  
  for(ll i = 0; i < p; i++) {
    ll u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
    capacity[u][v] += 1;
  }

  network_flow(1, 2);

  answer = 0;
  for(ll next: e[1]) {
    answer += flow[1][next];
  }

  cout << answer << '\n';
  
  return 0;
}