#include <bits/stdc++.h>
#define INF 999999999999
#define MAXN 55
#define MAXP 22
typedef long long ll;
using namespace std;

enum Direction {
  E,
  W,
  S,
  N,
  NONE
};

ll n, m, sy, sx, p, w[MAXN][MAXN], visited[MAXN][MAXN];
ll dy[4] = {0, 0, 1, -1};
ll dx[4] = {1, -1, 0, 0};
Direction directions[4] = {E, W, S, N};

ll dfs(ll y, ll x, ll p, Direction d, ll flow) {
  if(p == 0) return flow;
  ll result = flow + w[y][x];
  for(ll k = 0; k < 4; k++) {
    ll ny = y + dy[k], nx = x + dx[k];
    Direction nd = directions[k];
    ll np = d == nd ? p - 1 : p - 2;
    if(d == NONE) np = p;
    if(ny < n && ny >= 0 && nx < m && nx >= 0 && np >= 0 && !visited[ny][nx]) {
      visited[ny][nx] = true;
      result = max(result, dfs(ny, nx, np, nd, flow + w[y][x]));
      visited[ny][nx] = false;
    }
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < m; j++) {
      cin >> w[i][j];
    }
  }

  cin >> sy >> sx >> p;

  if(p == 0) {
    cout << w[sy][sx] << '\n';
    return 0;
  }
  visited[sy][sx] = true;
  cout << dfs(sy, sx, p, NONE, 0) << '\n';
  
  return 0;
}