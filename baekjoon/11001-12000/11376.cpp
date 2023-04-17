#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, m, k, x, occupied[1010], visited[1010], answer;
vector<ll> e[1010];

bool dfs(ll now) {
  for(ll next: e[now]) {
    if(visited[next] || occupied[next] == now) continue;
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
  for(ll i = 0; i < n; i++) {
    cin >> k;
    for(ll j = 0; j < k; j++) {
      cin >> x;
      e[i].push_back(x);
    }
  }

  fill(occupied, occupied + m + 1, -1);
  for(ll i = 0; i < n; i++) {
    fill(visited, visited + m + 1, 0);
    if(dfs(i)) answer++;
  }
  for(ll i = 0; i < n; i++) {
    fill(visited, visited + m + 1, 0);
    if(dfs(i)) answer++;
  }

  cout << answer << '\n';

  return 0;
}