#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll n;
vector<vector<ll>> e;
vector<ll> visited, answer;
map<ll, ll> cycle;

bool dfs(ll now, ll parent, vector<ll>& path) {
  for(ll next: e[now]) {
    if(next == parent) continue;
    if(!visited[next]) {
      visited[next] = true;
      path.push_back(next);
      if(!dfs(next, now, path)) {
        path.pop_back();
        visited[next] = false;
      } else {
        return true;
      }
    } else {
      while(path.size() && path.back() != next) {
        cycle[path.back()]++;
        path.pop_back();
      }
      cycle[next]++;
      return true;
    }
  }

  return false;
}

void get_answer(ll now, ll parent) {
  for(ll next: e[now]) {
    if(next == parent) continue;
    answer[next] = answer[now] + 1;
    get_answer(next, now);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  e.resize(n + 1);
  visited.assign(n + 1, false);
  answer.assign(n + 1, 0);
  for(ll i = 0; i < n; i++) {
    ll u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }

  vector<ll> path;
  visited[1] = true;
  path.push_back(1);
  dfs(1, -1, path);

  for(auto [key, _]: cycle) {
    if(e[key].size() > 2) {
      for(ll next: e[key]) {
        if(cycle.count(next)) continue;
        answer[next] = 1;
        get_answer(next, key);
      }
    }
  }

  for(ll i = 1; i <= n; i++) {
    cout << answer[i] << ' ';
  }
  
  return 0;
}