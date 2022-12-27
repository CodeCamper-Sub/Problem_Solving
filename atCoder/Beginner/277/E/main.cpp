#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll N, M, K, u, v, a, s;
vector<ll> e[2][200200];
ll visited[200200][2];
bool has_switch[200200];

queue<tuple<ll, ll, ll>> q; // {현재 위치, 상태, 거리}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M >> K;
  for(ll i = 0; i < M; i++) {
    cin >> u >> v >> a;
    if(a == 0) {
      e[0][u].push_back(v);
      e[0][v].push_back(u);
    } else {
      e[1][u].push_back(v);
      e[1][v].push_back(u);
    }
  }
  for(ll i = 0; i < K; i++) {
    cin >> s;
    has_switch[s] = true;
  }

  for(ll i = 0; i <= N; i++) {
    visited[i][0] = INF;
    visited[i][1] = INF;
  }

  q.push({1, 1, 0});
  while(!q.empty()) {
    ll now = get<0>(q.front());
    ll now_status = get<1>(q.front());
    ll now_distance = get<2>(q.front());
    q.pop();
    if(now_distance > visited[now][now_status]) continue;
    for(ll next: e[now_status][now]) {
      if(visited[next][now_status] > now_distance + 1) {
        visited[next][now_status] = now_distance + 1;
        q.push({next, now_status, now_distance+1});
      }
    }
    if(has_switch[now]) {
      ll next_status = 1 - now_status;
      for(ll next: e[next_status][now]) {
        if(visited[next][next_status] > now_distance + 1) {
          visited[next][next_status] = now_distance + 1;
          q.push({next, next_status, now_distance + 1});
        }
      }
    }
  }

  if(visited[N][0] == INF && visited[N][1] == INF) {
    cout << -1 << '\n';
  } else {
    cout << min(visited[N][0], visited[N][1]) << '\n';
  }

  return 0;
}