#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, k;
vector<ll> parent;
vector<vector<ll>> visited;
set<ll> origins;
ll dy[4] = {0, 0, 1, -1};
ll dx[4] = {1, -1, 0, 0};

ll Find(ll a) {
  if(parent[a] == -1) return a;
  else return parent[a] = Find(parent[a]);
}

bool Union(ll a, ll b) {
  a = Find(a);
  b = Find(b);
  if(a == b) return false;
  if(origins.find(a) != origins.end()) swap(a, b);
  parent[a] = b;
  if(origins.find(a) != origins.end()) origins.erase(a);
  return true;
}

ll flatten(ll y, ll x) {
  return y * n + x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;
  visited.assign(n, vector<ll>(n, false));
  parent.assign(n * n, -1);
  queue<pair<ll, ll>> q;
  for(ll i = 0; i < k; i++) {
    ll y, x;
    cin >> y >> x;
    y--; x--;
    origins.insert(flatten(y, x));
    for(ll k = 0; k < 4; k++) {
      ll ny = y + dy[k], nx = x + dx[k];
      if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
      if(visited[ny][nx]) {
        Union(flatten(y, x), flatten(ny, nx));
      }
    }
    visited[y][x] = true;
    q.push({y, x});
  }

  ll answer = 0;
  while(q.size()) {
    if(origins.size() == 1) break;
    answer++;
    ll tt = q.size();
    while(tt--) {
      auto [y, x] = q.front();
      q.pop();
      for(ll k = 0; k < 4; k++) {
        ll ny = y + dy[k], nx = x + dx[k];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        Union(flatten(ny, nx), flatten(y, x));
        if(!visited[ny][nx]) {
          for(ll t = 0; t < 4; t++) {
            ll nny = ny + dy[k], nnx = nx + dx[k];
            if(nny < 0 || nny >= n || nnx < 0 || nnx >= n) continue;
            if(visited[nny][nnx]) {
              Union(flatten(ny, nx), flatten(nny, nnx));
            }
          }
          visited[ny][nx] = true;
          q.push({ny, nx});
        }
      }
    }
  }

  cout << answer << '\n';
  
  
  return 0;
}