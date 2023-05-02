#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

vector<vector<ll>> grid;
ll k, x, y, id, n;

bool operator!=(const pair<int, int>& lhs, const pair<int, int>& rhs) {
  return !(lhs == rhs); // == 연산자의 결과를 논리 부정하여 반환
}

void draw(ll r, ll c, ll len, pair<ll, ll> direction) {
  if(len == 2) {
    ++id;
    if(direction != make_pair(0ll, 0)) {
      grid[r][c] = id;
    }
    if(direction != make_pair(1ll, 0)) {
      grid[r + 1][c] = id;
    }
    if(direction != make_pair(0ll, 1)) {
      grid[r][c + 1] = id;
    }
    if(direction != make_pair(1ll, 1)) {
      grid[r + 1][c + 1] = id;
    }
    grid[y][x] = -1;
    return;
  }
  if(r <= y && y < r + len && c <= x && x < c + len) {
    if(r <= y && y < r + len / 2 && c <= x && x < c + len / 2) {
      direction = {0, 0};
      draw(r, c, len / 2, {-1, -1});
    } else if(r + len / 2 <= y && c <= x && x < c + len / 2) {
      direction = {1, 0};
      draw(r + len / 2, c, len / 2, {-1, -1});
    } else if(r <= y && y < r + len / 2 && c + len / 2 <= x) {
      direction = {0, 1};
      draw(r, c + len / 2, len / 2, {-1, -1});
    } else {
      direction = {1, 1};
      draw(r + len / 2, c + len / 2, len / 2, {-1, -1});
    }
  }
  if(direction != make_pair(0ll, 0)) {
    draw(r, c, len / 2, {1, 1});
  }
  if(direction != make_pair(1ll, 0)) { 
    draw(r + len / 2, c, len / 2, {0, 1});
  }
  if(direction != make_pair(0ll, 1)) {
    draw(r, c + len / 2, len / 2, {1, 0});
  }
  if(direction != make_pair(1ll, 1)) {
    draw(r + len / 2, c + len / 2, len / 2, {0, 0});
  }
  draw(r + len / 4, c + len / 4, len / 2, direction);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> k >> x >> y;
  n = pow(2, k);
  x -= 1;
  y = n - y;
  grid.assign(n, vector<ll>(n, -1));
  draw(0, 0, n, {-1, -1});
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < n; j++) {
      cout << grid[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}