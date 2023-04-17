#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt, n, m, a, b, visited[1010], occupied[1010], answer;
vector<ll> e[1010];

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

void solve() {
  fill(occupied, occupied + n + 1, -1);
  for(ll i = 0; i < m; i++) {
    fill(visited, visited + n + 1, 0);
    if(dfs(i)) answer++;
  }

  cout << answer << '\n';
}

void init() {
  answer = 0;
  cin >> n >> m;
  for(ll i = 0; i <= m  ; i++) e[i].clear();
  for(ll i = 0; i < m; i++) {
    cin >> a >> b;
    for(ll j = a; j <= b; j++) {
      e[i].push_back(j);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> tt;
  while(tt--) {
    init();
    solve();
  }
  
  return 0;
}