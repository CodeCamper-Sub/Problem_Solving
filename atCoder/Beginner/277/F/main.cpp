#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll H, W, A;
vector<vector<ll>> grid;
vector<pair<ll, ll>> min_max;
vector<ll> e[2000200];
ll ind[2000200];
bool visited[2000200];
ll memo[2000200];

bool dfs(ll now) {
  if(memo[now] != -1) {
    return memo[now];
  }
  bool is_possible = true;
  for(ll next: e[now]) {
    if(!visited[next]) {
      visited[next] = true;
      is_possible &= dfs(next);
      visited[next] = false;
      if(!is_possible) break;
    } else {
      return memo[now] = 0;
    }
  }
  return memo[now] = is_possible ? 1 : 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> H >> W;

  for(ll i = 0; i < H; i++) {
    vector<ll> row;
    for(ll j = 0;j < W; j++) { 
      cin >> A;
      row.push_back(A);
    }
    grid.push_back(row);
  }

  for(ll i = 0; i < H; i++) {
    ll minimum = INF;
    ll maximum = -INF;
    for(ll j = 0; j < W; j++) {
      if(grid[i][j] == 0) continue;
      minimum = min(minimum, grid[i][j]);
      maximum = max(maximum, grid[i][j]);
    }
    if(maximum == INF) continue;
    min_max.push_back({minimum, maximum});
  }

  sort(min_max.begin(), min_max.end());
  bool is_possible = true;
  for(ll i = 1; i < min_max.size(); i++) {
    if(min_max[i].first < min_max[i-1].second) {
      is_possible = false;
      break;
    }
  }

  if(!is_possible) {
    cout << "No\n";
    return 0;
  }

  for(ll i = 0; i < H; i++) {
    vector<pair<ll, ll>> v;
    for(ll j = 0; j < W; j++) {
      if(grid[i][j] == 0) continue;
      v.push_back({grid[i][j], j});
    }
    sort(v.begin(), v.end());
    for(ll i = 1; i < v.size(); i++) {
      if(v[i].first != v[i-1].first) {
        for(ll j = i-1; j >= 0; j--) {
          if(v[j].first != v[i-1].first) break;
          e[v[j].second].push_back(W + v[i-1].first);
          ind[W + v[i-1].first]++;
        }
        for(ll j = i; j < v.size(); j++) {
          if(v[j].first != v[i].first) break;
          e[W + v[i-1].first].push_back(v[j].second);
          ind[v[j].second]++;
        }
      }
    }
  }

  is_possible = false;
  for(ll i = 0; i < W; i++) {
    if(ind[i] == 0) {
      is_possible = true;
      break;
    }
  }
  if(!is_possible) {
    cout << "No\n";
    return 0;
  }
  memset(memo, -1, 2000200*sizeof(ll));
  for(ll i = 0; i < W; i++) {
    if(ind[i] == 0) {
      visited[i] = true;
      is_possible &= dfs(i);
      visited[i] = false;
      if(!is_possible) break;
    }
  }

  if(is_possible) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

  return 0;
}