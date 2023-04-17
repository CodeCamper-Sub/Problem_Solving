#include <bits/stdc++.h>
#define INF 999999999999
#define MAX 5
typedef long long ll;
using namespace std;

char grid[MAX][MAX], to_grid[MAX][MAX];
ll visited[MAX * MAX], answer;
vector<pair<ll, ll>> from, to;
vector<ll> path;

void dfs(ll now) {
  if(path.size() == from.size()) {
    ll partial_answer = 0;
    for(ll i = 0; i < path.size(); i++) {
      partial_answer += abs(from[path[i]].first - to[i].first) + abs(from[path[i]].second - to[i].second);
    }
    if(partial_answer == 7) {
      cout << "";
    }
    answer = min(answer, partial_answer);
    return;
  }
  for(ll i = 0; i < from.size(); i++) {
    if(!visited[i]) {
      visited[i] = true;
      path.push_back(i);
      dfs(i);
      path.pop_back();
      visited[i] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  for(ll i = 0; i < 4; i++) {
    for(ll j = 0; j < 4; j++) {
      cin >> grid[i][j];
    }
  }

  for(ll i = 0; i < 4; i++) {
    for(ll j = 0; j < 4; j++) {
      cin >> to_grid[i][j];
    }
  }

  for(ll i = 0; i < 4; i++) {
    for(ll j = 0; j < 4; j++) {
      if(grid[i][j] != to_grid[i][j]) {
        if(grid[i][j] == 'L') {
          from.push_back({i, j});
        } else {
          to.push_back({i, j});
        }
      }
    }
  }

  if(from.size() == 0) {
    cout << 0 << '\n';
    return 0;
  }

  fill(visited, visited + MAX * MAX, false);
  answer = INF;
  for(ll i = 0; i < from.size(); i++) {
    if(!visited[i]) {
      visited[i] = true;
      path.push_back(i);
      dfs(i);
      path.pop_back();
      visited[i] = false;
    }
  }

  cout << answer << '\n';
  
  return 0;
}