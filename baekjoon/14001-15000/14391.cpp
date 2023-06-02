#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m;
vector<vector<ll>> grid;
vector<vector<ll>> visited;
vector<ll> memo;

ll recursion(ll status) {
  if(memo[status] != -1) return memo[status];
  ll y = -1, x = -1;
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < m; j++) {
      if(!visited[i][j]) {
        y = i;
        x = j;
        break;
      }
    }
    if(y != -1) break;
  }
  if(y == -1) return memo[status] = 0;
  ll sum = 0;
  // 가로로 놓기
  ll next_status = status;
  ll k = x;
  for(ll i = x; i < m; i++) {
    if(visited[y][i]) break;
    k = i;
    sum *= 10;
    sum += grid[y][i];
    visited[y][i] = true;
    next_status |= (1ll << (y * m + i));
    memo[status] = max(memo[status], sum + recursion(next_status));
  }
  for(ll i = k; i >= x; i--) {
    visited[y][i] = false;
    next_status ^= (1ll << (y * m + i));
  }
  
  // 세로로 놓기
  sum = 0;
  k = y;
  for(ll i = y; i < n; i++) {
    if(visited[i][x]) break;
    k = i;
    sum *= 10;
    sum += grid[i][x];
    visited[i][x] = true;
    next_status |= (1ll << (i * m + x));
    memo[status] = max(memo[status], sum + recursion(next_status));
  }
  for(ll i = k; i >= y; i--) {
    visited[i][x] = false;
  }

  return memo[status];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  grid.assign(n, vector<ll>(m));
  visited.assign(n, vector<ll>(m, false));
  memo.assign((1ll << n * m), -1);
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < m; j++) {
      char c;
      cin >> c;
      grid[i][j] = c - '0';
    }
  }

  cout << recursion(0) << '\n';
  
  return 0;
}