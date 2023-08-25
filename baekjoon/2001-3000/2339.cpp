#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n;
vector<vector<ll>> grid;
vector<vector<vector<ll>>> visited;

ll flatten(ll y, ll x) {
  return y * n + x;
}

pair<ll, ll> unflatten(ll k) {
  return {k / n, k % n};
}

ll dfs(ll last_cut_direction, ll tleading, ll btrailing) { // last_cut_direction -> 0: 자른 적 없음, 1: 가로, 2: 세로
  if(visited[last_cut_direction][tleading][btrailing] != -1) return visited[last_cut_direction][tleading][btrailing];
  ll& result = visited[last_cut_direction][tleading][btrailing];
  result = 0;
  
  auto [sy, sx] = unflatten(tleading);
  auto [ey, ex] = unflatten(btrailing);

  ll impurity_cnt = 0;
  ll jewel_cnt = 0;
  for(ll i = sy; i <= ey; i++) {
    for(ll j = sx; j <= ex; j++) {
      if(grid[i][j] == 1) impurity_cnt++;
      else if(grid[i][j] == 2) jewel_cnt++;
    }
  }

  if(impurity_cnt == 0) {
    if(jewel_cnt <= 1) return result = 1;
    else return result = 0;
  }

  if(last_cut_direction == 0 || last_cut_direction == 1) {
    // 세로로 자르기
    for(ll j = sx + 1; j < ex; j++) {
      ll impurity_cnt = 0;
      ll jewel_cnt = 0;
      for(ll i = sy; i <= ey; i++) {
        if(grid[i][j] == 1) impurity_cnt++;
        else if(grid[i][j] == 2) jewel_cnt++;
      }
      if(impurity_cnt > 0 && jewel_cnt == 0) {
        result += dfs(2, tleading, flatten(ey, j - 1)) * dfs(2, flatten(sy, j + 1), btrailing);
      }
    }
  }

  if(last_cut_direction == 0 || last_cut_direction == 2) {
    // 가로로 자르기
    for(ll i = sy + 1; i < ey; i++) {
      ll impurity_cnt = 0;
      ll jewel_cnt = 0;
      for(ll j = sx; j <= ex; j++) {
        if(grid[i][j] == 1) impurity_cnt++;
        else if(grid[i][j] == 2) jewel_cnt++;
      }
      if(impurity_cnt > 0 && jewel_cnt == 0) {
        result += dfs(1, tleading, flatten(i - 1, ex)) * dfs(1, flatten(i + 1, sx), btrailing);
      }
    }
  }

  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  grid.assign(n, vector<ll>(n));

  for(ll i = 0; i < n; i++) for(ll j = 0; j < n; j++) cin >> grid[i][j];
  visited.resize(3);
  for_each(visited.begin(), visited.end(), [](auto& layer) { layer.assign(n * n, vector<ll>(n * n, -1)); });

  ll answer = dfs(0, flatten(0, 0), flatten(n - 1, n - 1));

  cout << (answer != 0 ? answer : -1) << '\n';

  return 0;
}