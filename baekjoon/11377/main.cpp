#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, m, k, t, x, occupied[1010], visited[1010], answer, extra_answer;
vector<ll> e[2020];

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

  cin >> n >> m >> k;
  for(ll i = 0; i < n; i++) {
    cin >> t;
    while(t--) {
      cin >> x;
      e[i].push_back(x);
      e[n+i].push_back(x);
    }
  }

  fill(occupied, occupied + m + 1, -1);
  for(ll i = 0; i < 2 * n; i++) {
    fill(visited, visited + m + 1, 0);
    dfs(i);
  }

  for(ll i = 1; i <= m; i++) {
    if(occupied[i] != -1 && occupied[i] < n) answer++;
    else if(occupied[i] != -1) extra_answer++;
  }

  cout << answer + min(extra_answer, k) << '\n';
  
  return 0;
}