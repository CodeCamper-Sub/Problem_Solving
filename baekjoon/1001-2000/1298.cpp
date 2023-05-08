#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m, answer;
vector<ll> occupied, visited;
vector<vector<ll>> e;

bool dfs(ll now) {
  for(ll next: e[now]) {
    if(visited[next]) continue;
    visited[next] = true;
    if(occupied[next] == -1 || dfs(occupied[next])) {
      occupied[next] = now;
      return true;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  e.resize(n + 1);
  for(ll i = 0; i < m; i++) {
    ll a, b;
    cin >> a >> b;
    e[a].push_back(b);
  }

  occupied.assign(n + 1, -1);
  for(ll i = 1; i <= n; i++) {
    visited.assign(n + 1, false);
    if(dfs(i)) answer++;
  }

  cout << answer << '\n';
  
  return 0;
}