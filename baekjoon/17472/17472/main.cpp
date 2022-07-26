//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m, grid[20][20], id, answer;
ll dy[4] = {-1, 0, 1, 0};
ll dx[4] = {0, 1, 0, -1};
bool visited[20][20], visited_islands[10];
ll e[10][10];

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= m; j++) {
      cin >> grid[i][j];
    }
  }
  id = 0;
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= m; j++) {
      if(!visited[i][j] && grid[i][j] == 1) {
        id++;
        queue<pair<ll, ll>> q;
        visited[i][j] = true;
        q.push({i, j});
        while(!q.empty()) {
          ll nowY = q.front().first;
          ll nowX = q.front().second;
          q.pop();
          grid[nowY][nowX] = id;
          for(ll k = 0; k < 4; k++) {
            ll nextY = nowY + dy[k];
            ll nextX = nowX + dx[k];
            if(nextY >= 1 && nextY <= n && nextX >= 1 && nextX <= m && !visited[nextY][nextX] && grid[nextY][nextX]) {
              visited[nextY][nextX] = true;
              q.push({nextY, nextX});
            }
          }
        }
      }
    }
  }
  for(ll i = 0; i <= id; i++) {
    for(ll j = 0; j <= id; j++) {
      e[i][j] = LONG_LONG_MAX;
    }
  }
  
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= m; j++) {
      ll origin = grid[i][j];
      if(origin == 0) continue;
      for(ll k = 1; i - k >= 1; k++) {
        ll dest = grid[i-k][j];
        if(dest != 0) {
          if(k >= 3 && origin != dest) {
            e[origin][dest] = min(e[origin][dest], k - 1);
          }
          break;
        }
      }
      for(ll k = 1; i + k <= n; k++) {
        ll dest = grid[i+k][j];
        if(dest != 0) {
          if(k >= 3 && origin != dest) {
            e[origin][dest] = min(e[origin][dest], k - 1);
          }
          break;
        }
      }
      for(ll k = 1; j - k >= 1; k++) {
        ll dest = grid[i][j-k];
        if(dest != 0) {
          if(k >= 3 && origin != dest) {
            e[origin][dest] = min(e[origin][dest], k - 1);
          }
          break;
        }
      }
      for(ll k = 1; j + k <= m; k++) {
        ll dest = grid[i][j+k];
        if(dest != 0) {
          if(k >= 3 && origin != dest) {
            e[origin][dest] = min(e[origin][dest], k - 1);
          }
          break;
        }
      }
    }
  }
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
  visited_islands[1] = true;
  for(ll i = 1; i <= id; i++) {
    if(e[1][i] != LONG_LONG_MAX) {
      q.push({e[1][i], i});
    }
  }
  while(!q.empty()) {
    ll cost = q.top().first;
    ll now = q.top().second;
    q.pop();
    if(visited_islands[now]) continue;
    visited_islands[now] = true;
    answer += cost;
    for(ll i = 1; i <= id; i++) {
      if(e[now][i] != LONG_LONG_MAX && !visited_islands[i]) {
        q.push({e[now][i], i});
      }
    }
  }
  
  for(ll i = 1; i <= id; i++) {
    if(!visited_islands[i]) {
      cout << -1 << '\n';
      return 0;
    }
  }
  cout << answer << '\n';
  
  return 0;
}

