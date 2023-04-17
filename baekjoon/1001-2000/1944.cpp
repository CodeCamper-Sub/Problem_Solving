#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, m, answer;
vector<vector<char>> grid;
vector<pair<ll, ll>> nodes;
vector<vector<ll>> dist, visited;
vector<ll> parent;
ll dy[4] = {0, 0, 1, -1};
ll dx[4] = {1, -1, 0, 0};

priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> q;

ll find(ll a) {
  if(parent[a] == -1) return a;
  else return parent[a] = find(parent[a]);
}

void _union(ll a, ll b) {
  a = find(a);
  b = find(b);
  parent[a] = b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  grid.assign(n, vector<char>(n));
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < n; j++) {
      cin >> grid[i][j];
      if(grid[i][j] == 'K' || grid[i][j] == 'S') {
        nodes.push_back({i, j});
      }
    }
  }
  dist.assign(nodes.size(), vector<ll>(nodes.size(), INF));
  for(ll i = 0; i < nodes.size(); i++) {
    visited.assign(n, vector<ll>(n, INF));
    queue<pair<ll, ll>> q;
    visited[nodes[i].first][nodes[i].second] = 0;
    q.push({nodes[i].first, nodes[i].second});
    while(q.size()) {
      auto [y, x] = q.front();
      q.pop();
      for(ll k = 0; k < 4; k++) {
        ll ny = y + dy[k], nx = x + dx[k];
        if(ny >= n || ny < 0 || nx >= n || nx < 0 || grid[ny][nx] == '1') continue;
        if(visited[ny][nx] > visited[y][x] + 1) {
          visited[ny][nx] = visited[y][x] + 1;
          q.push({ny, nx});
        }
      }
    }
    for(ll j = 0; j < nodes.size(); j++) {
      dist[i][j] = visited[nodes[j].first][nodes[j].second];
      if(dist[i][j] == INF) {
        cout << -1 << '\n';
        return 0;
      }
    }
  }

  parent.assign(nodes.size(), -1);
  for(ll i = 0; i < nodes.size(); i++) {
    for(ll j = i + 1; j < nodes.size(); j++) {
      q.push({dist[i][j], i, j});
    }
  }

  answer = 0;
  while(q.size()) {
    auto [w, a, b] = q.top();
    q.pop();
    if(find(a) != find(b)) {
      _union(a, b);
      answer += w;
    }
  }

  cout << answer << '\n';

  return 0;
}