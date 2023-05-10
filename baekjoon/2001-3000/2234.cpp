#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m, id;
ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, -1, 0, 1};

vector<vector<ll>> adj, block_adj;
vector<vector<ll>> visited;
vector<ll> sizes;

ll flatten(ll y, ll x) {
  return y * m + x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> m >> n;
  adj.assign(n * m, vector<ll>(n * m, 0));
  for(ll i = 0; i < n; i++) for(ll j = 0; j < m; j++) {
    ll k, now = flatten(i, j);
    cin >> k;
    for(ll d = 0; d < 4; d++) {
      ll ny = i + dy[d], nx = j + dx[d];
      ll next = flatten(ny, nx);
      if(!(k & (1ll << d))) {
        adj[now][next] = 1;
        adj[next][now] = 1;
      }
    }
  }

  visited.assign(n, vector<ll>(m, -1));

  for(ll y = 0; y < n; y++) for(ll x = 0; x < m; x++) {
    if(visited[y][x] == -1) {
      queue<pair<ll, ll>> q;
      visited[y][x] = id;
      q.push({y, x});
      ll size = 1;
      while(q.size()) {
        auto [y, x] = q.front();
        ll now = flatten(y, x);
        q.pop();
        for(ll k = 0; k < 4; k++) {
          ll ny = y + dy[k], nx = x + dx[k];
          ll next = flatten(ny, nx);
          if(ny >= 0 && ny < n && nx >= 0 && nx < m && visited[ny][nx] == -1 && adj[now][next]) {
            visited[ny][nx] = id;
            size++;
            q.push({ny, nx});
          }
        }
      }
      sizes.push_back(size);
      id++;
    }
  }

  block_adj.assign(id, vector<ll>(id, 0));
  for(ll y = 0; y < n; y++) for(ll x = 0; x < m; x++) {
    block_adj[visited[y][x]][visited[y][x]] = true;
    for(ll k = 0; k < 4; k++) {
      ll ny = y + dy[k], nx = x + dx[k];
      if(ny >= 0 && ny < n && nx >= 0 && nx < m && visited[y][x] != visited[ny][nx]) {
        block_adj[visited[y][x]][visited[ny][nx]] = 1;
        block_adj[visited[ny][nx]][visited[y][x]] = 1;
      }
    }
  }

  ll answer = 0;
  for(ll i = 0; i < id; i++) {
    for(ll j = i + 1; j < id; j++) {
      if(!block_adj[i][j]) continue;
      answer = max(answer, sizes[i] + sizes[j]);      
    }
  }

  cout << id << '\n';
  cout << *max_element(sizes.begin(), sizes.end()) << '\n';
  cout << answer << '\n';
  
  return 0;
}